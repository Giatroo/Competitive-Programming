# Usefull formulas for Binary Trees

## Number of possible binary trees

It's known as Catalan's numbers: $$C(n)=\dfrac{{2n \choose n}}{n+1}$$

### Number of possible labeled binary trees

If we consider that the order is important, than the number is 
$$C(n)\cdot n!$$


## Ranges for number of nodes and height

$h:= \textrm{ height }$
$n:= \textrm{ num. of nodes }$

$$\lceil\log_2n-1\rceil\leq h\leq n-1$$

$$h+1\leq n\leq 2^{h+1}-1$$

## Number of leaves 

$\#deg(i) := \textrm{  num. of nodes with degree i }$

$$\#deg(0) = \#deg(2)+1$$

## Number of null pointers (external nodes)

$$n+1$$

## Number of edges

$$n-1$$

# Strict Binary Trees

They are trees with no nodes with degree equal 1.

## Ranges for number of nodes and height in a Strict BT

$$2h+1\leq n\leq 2^{h+1}-1$$

$$\lceil\log_2n-1\rceil\leq h \leq \dfrac{n-1}{2}$$

## Number of leaves

$$leaves = internal + 1$$

## Full vs Complete Binary Tree

* A **full** binary tree is a tree that has $2^{h+1}-1$ for a height of $h$.

* A **complete** binary tree is a full binary tree with height $h-1$ and at the last level, the nodes must apper from the left to the right.

Every full binary tree is a complete binary tree