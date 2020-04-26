# Lowest Common Ancestor (LCA)

*Problem:* Given a rooted tree and two nodes `a` and `b`, find the lowest common ancestor between the two.

*Exemple:* supose the path between `a` and `r`, the root, is:
$$p(a) = \{a, x, y, z, r\}$$

and the path between `b` and `r` is:
$$p(b) = \{w, z, r\}$$

Then, $p(a)\cap p(b) = \{z, r\}$ is the set of common ancestors between `a` and `b`, and `z` is the lowest one, because it appears first in both paths.

## Algorithm 1

* Place `a` and `b` at the same level:
  * Choose the node with more depth and go up until it's at the same depth of the other node;
* Now go up with both nodes until they reach a common node, that's the LCA.

**Implementation:**

```cpp
if (depth(a) < depth(b)) swap(a, b)
while (depth(a) > depth(b)) a = a->parent
while (a != b) {
    a = a->parent
    b = b->parent
}
return a
```

**Analysis**

The code is O(n). If we have a perfect unbalanced tree and `a` equals the depthest node and `b` equals the root, then `a` will visit all nodes of our tree.

## Algorithm 2 (Dynamic Programming)

The ideia is the same (walk up the tree until the nodes are equal), but the difference is that we're not going to jump immediately front a node to its parent.
We'll do jumps of lenght $2^i$, because we'll be using that any number can be represented as a sum of powers of two.

For doing that, we need some pre-processing.

### Pre-processing

* Define `ancestor(2^i) of x` by the ancestor of `x` which is $2^i$ levels above `x`; 
* Let $L$ be the greatest integer such that $2^L < h$, where $h$ is the height of the tree. Then, we'll calculate for all vertices of the tree `ancestor(2^i)` for all $0\leq i\leq L$;

To compute such values, we'll define a recorrence:

$\begin{cases}
\textrm{anc}(2^i) \textrm{ of v = v->parent} &\textrm{case } i=0\\
\textrm{anc}(2^i) \textrm{ of v = anc}(2^{i-1})\textrm{ of anc}(2^{i-1})\textrm{ of v} &\textrm{otherwise }\\
\end{cases}$

**Code:**
```cpp
forall vertice v:
    anc[v][0] = v->parent
for i from 1 to L:
    forall vertice v:
        anc[v][i] = anc[anc[v][i-1]][i-1]
```

**Analysis:**

As $L = O(log~n)$, then the complexity of both time and space is $O(n~log~n)$.

One the see that the complexity is actually worst and the previous, but with this pre-processing, we can now querry for many LCAs in a better time as we'll see is the future.

### Query

* Make the depth of `a` and `b` equal;
* Find the depthest ancestor of `a` which parent is ancestor of both `a` and `b`. The parent of that node is the LCA.

The problem here is that we'll now make jumps that can be too large. For instance, supose I do a jump of $8$ levels from `a` and find `c` and then do a jump of $8$ levels from `b` and find the same `c`. Than, `c` is an ancestor of `a` and `b`, but I still don't know if `c` is the lowest one. Therefore, it's like I'm binary searching the levels until I find the LCA.

Whenever I find a node which is an ancestor, I know that can be the LCA, but we need to check lower nodes. And wheneven I find a node which isn't an acnestor, we now that we need to check higher nodes.

That leads of course to a $O(log~n)$ query, because it's essentialy binary search. 

**Implementation:**

```cpp
if (depth[a] < depth[b]) swap(a,b)

// Leveling a and b
for i from L to 0:
    if (depth[b] - 2^i >= depth[a]) b = anc[b][i] 

// Case where one was an ancestor of the other
if (a == b) return a 

for i from L to 0:
    if (anc[a][i] != anc[b][i]) {
        a = anc[a][i]
        b = anc[b][i]
    }
return a->parent
```

### Algorithm 3 (Optimizating with SegTrees)

We can make the previous algorithm a little bit faster using Segment Trees.
The complexity will be the same, but the constat factor is better.

Imagine we have all the vertices from the path from `a` to `b`. This path has the LCA. The LCA is the vertice with lowest depth! Therefore, we can use a Min SegTrees to find the LCA.

To get the vertices in the path, we can use Euler's path. So we use DFS and save the iteration in which we visited a node and the iteration that we returned to that node.

So we'll save in a vector where the indices are the iterations of the DFS and we have pair of what vertice we were at that itaration and what is its depth.

To find the LCA, we need to find any index of `a` and any index of `b` and query the minimum in $[a,~b]$.
