# Merge Sort Segment Tree

Today, we'll learn about a special type of segment tree witch answers the next problem:

**Problem:** Given an array **A** and two segments $[l, r]$ and $[a, b]$ give the amount of numbers in the array from the l-th to the r-th element that are between $a$ and $b$.

**Exemple:** $A = [1, 2, 4, 3, 7, 10, 4, 5]$ and $l = 2$, $r = 6$, $a = 1$, $b = 5$. 
Then, we look this subarray: $[4, 3, 7, 10, 4]$ and check which elements are greater then 1 and lower then 5. The numbers are 4, 3 and 4.
Therefore, the answer is **3**.

Some more exemples for this same array:
* If $l = 2, \ r = 4, \ a = 5, \ b = 10$, then subarray is $[4, 3, 7]$ and answer is $1$;
* If $l = 0, \ r = 4, \ a = 3, \ b = 6$, then subarray is $[1, 2, 4, 3, 7]$ and answer is $2$;
* If $l = 4, \ r = 7, \ a = 3, \ b = 15$, then subarray is $[7, 10, 4, 5]$ and answer is $4$;
* If $l = 0, \ r = 7, \ a = -10, \ b = 15$, then subarray is A and answer is $8$ (all the elements).
---

## The tree

For answering that problem, we'll use the logic behind segment trees and use the next fact: 
* if the array is sorted, we can binary search $a$ and $b$ finding the index of those elements, say $i$ and $j$ and do $j-i+1$ for finding the number of elements we want. Actually, $a$ and $b$ may not be in the array. So we want to find the closest value to $a$ but greater then it and the closest value to $b$ but lower then it.

This fact alone is not enough because we can't sort the original array. Doing that will result in losing the segments of the array. Then, we use the logic of segment trees to save sorted segments of the array.

For instance, if the array is $A = [1, 2, 4, 3, 7, 10, 4, 5]$, we'll create a segment tree in which the leaves are the original elements and all internal nodes have the following property: it is the sorted union of its children.

So it would be something like this:

```
    ( [1, 2, 3, 4, 4, 5, 7, 10] )
          /               \
    ( [1, 2, 3, 4] )   ( [4, 5, 7, 10] )
      /         \          /         \
 ([1, 2])    ([3, 4])  ([7, 10])  ([4, 5])
  /    \       /  \      /    \     /    \
 ([1])([2]) ([4])([3]) ([7])([10]) ([4])([5])
```

By looking at this tree should see why the tecnich is known as Mergesort Tree.
That looks exacly equal to the recursion done in a mergesort.

And we'll really use the algorithm of merging to build this tree since the invariant of the internal nodes is exactly joing two sorted arrays into one sorted array.

---
*Before* checking the implementation though, we need to understand how to perform queries in this DS.
Taking the first exemple ($l = 2$, $r = 6$, $a = 1$, $b = 5$), we need the segment from the first 4 til the second one. The nodes that represent this segment are ([3, 4]), ([7, 10]) and ([4]). As all this subsegments are sorted, we can beform binary search on them and get our answer for each of them. For ([3, 4]) the answer is 2, for ([7, 10]) the answer is 0 and for ([4]) the answer is 1. Now, we can just sum the answers (since the segments are disjoined) the return **3**. =D

---

## Implementation

```cpp
const int N = 112345;
int a[N];           // 1-indexed
vector<int> t[4*N]; // 1-indexed

void build(int l, int r, int i) {
  // If it's a leaf, the vector contains just the element
  if (l == r) t[i].push_back(a[l]);
  else {
    // Else we need to build both halfs and
    // use mergesort's algorthm with its
    // children to create the sorted union of them
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    merge(t[2*i].begin(), t[2*i].end(), 
          t[2*i+1].begin(), t[2*i+1].end(),
          back_inserter(t[i]));
    // merge is a C++ function
    
  }
}

// For the query, it's pretty much the same thing
// as any segtree but we have the a and b parameters
int query(int l, int r, int i, int ql, int qr, int a, int b) {
  if (ql <= l && r <= qr) {
    // Again we'll use cpp functions
    return upper_bound(t[i].begin(), t[i].end(), b) -
           lower_bound(t[i].begin(), t[i].end(), a);
    //lower_bound returns an interator to the first element equal or greater than a
    //upper_bound returns an interator to the first element greater than b

  }
  if (r < ql || qr < l) return 0;
  int m = (l+r)/2;
  return query(2*i, l, m, ql, qr, a, b) + 
         query(2*i+1, m+1, r, ql, qr, a, b);

}
```