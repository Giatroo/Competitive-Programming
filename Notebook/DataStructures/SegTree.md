# Segment Trees

Segment Trees are an important data structure in CS. They solve the problem below:

*Supose you have an array of **N** elements $a_1, a_2, \cdots, a_n$ and can perform two such operations:*

1. You are given two numbers $l$ and $r$ ($l \leq r$) and must return the sum of $(a_l, a_{l+1}, \cdots, a_{r-1}, a_r)$;
2. You are given two number $p$ and $v$ and must add $v$ to $a_p$.

The naive way of solving that is doing a for loop for the first operation (it costs O(r-l) operations) and a simples attribution to $a_p$ (it costs O(1) operations).

Instead of that, the segment tree perform both operations in O(log(N)) in the worst case. Moreover we'll see that segment trees can do operation 2. not just for a single element of the array but for a range like operation 1. (you're given three numbers $l$, $r$, $v$ and must add $v$ to all elements $(a_l, \cdots, a_r)$). 

The first operation is called query and the second one is called update.
When we do an operation in a single element, we call this a point-operation.
When we do an operation in an interval for the array, we call this a range-operation.

So now, let's see the code for the different types os segtrees.

### Range-Query Point-Update Segment Trees

These are the ones that solve the original problem. We have a binary tree where the leaf nodes have the values of the original arrays and each internal node is the sum of its children.
Then, we say that the root represents the segment $[1, n]$, its left child represents the interval $\left[1, \dfrac{n}{2}\right]$ and its right child represents the interval $\left[\dfrac{n}{2}+1, n\right]$ and so on. For any node that represents an interval $[i, j]$ its children represent that same interval but partitioned in the middle (half for each child).

To code that, we need the original array $arr[1\cdots N]$, the tree array $t[1\cdots 4N]$ and three procedures `build`, `update` and `querry`.

```cpp
    int n;
    // These arrays are 1-indexed (that's important)
    int arr[n], t[4*n];

    // To build, we use a recursive function with parameters
    // the left and right points of the segment and
    // the current node in the tree
    // (the tree is represented by an array)
    void build(int l, int r, int i)
    {
        // if we're in a leaf
        if (l == r) // the value of the tree is the value of the array
            t[i] = arr[l];
        else {
            // we pick the middle point of the segment
            int m = (l+r)/2;
            // build the left and right children
            build(1, m, 2*i);
            build(m+1, r, 2*i+1);
            // and set the value of the node 
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    // To update, we use a recursive function with parameters
    // the left and right points of the current segment,
    // the current node in the tree,
    // the point that we want to update and
    // the value that we'll add in the point
    //
    // Notice that updating a point means that we need to
    // update all the nodes in the path from the root to the
    // leaf.
    void update(int l, int r, int i, int p, int v)
    {
        // if we're in the leaf
        if (l == r) // update it directly
            t[i] += v;
        else {
            // we pick the middle point
            int m = (l+r)/2;
            // and use binary search property to find the position p
            if (p <= m) // if p is to the left
                update(l, m, 2*i, p, v); // update the left child
            else
                update(m+1, r, 2*i+1, p, v); // update the right child
            // (2i is the left child and 2i+1 is the right one)

            // after updating the children, update the current node
            t[i] = t[2*i] + t[2*i+1];
        }
    }


    // To query, we use a recursive function with parameters
    // the left and right points of the current segment,
    // the current node in the tree and
    // the left and right points of the query segment
    //
    // There are three possibilities:
    // * the current segment is entirely inside the querry segment
    // * the current segment is partially inside the querry segment
    // * the current segment is entirely outside the querry segment
    int query(int l, int r, int i, int ql, int qr)
    {
        // if the current segment is entirely inside the querry segment
        if (ql <= l && r <= qr) {
            // return the value of the current node because this segment is
            // relevant for the entirely ql, qr segment
            return t[i];
            // as the children of i are all inside the querry segment, 
            // we could go further, but that's not necessary because
            // t[i] contains all the information we need
        }

        // if the current segment is outside the querry segment,
        // just return a value that doesn't change the final value
        if (l > qr || r < ql) return 0;

        // If this line is executed, we're in a partial overlap situation
        int m = (l+r)/2; //pick the middle point
        // And find the segments that we care about in the children
        return query(l, m, 2*i, ql, qr) + query(m+1, r, 2*i+1, ql, qr);
    }
```

Notice one thing which is very important in segment trees. We could do other types of segment tree with other operations instead of addition. That could multiplication, finding the min or the max or any other associative math operation. Moreover, we could set the value of $a_p$ to be $v$ instead of adding $v$. (we could do actually any operation we want). That's the powerness of this data structure.

