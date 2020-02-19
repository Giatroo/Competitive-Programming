# Change Making Problem

In this problem, we have a set $S$ of coins values and want to sum some change $C$.

For instance, supose $S = \{2, 5, 7\}$ and $C = 17$.

This problem has lots of flavors. The simplest one is determinating if it's possible or not to sum C. Another one is to determinate the amount of ways we can sum C. And there are many others flavors.

We'll start studying the flavor where we have infinitly many coins of each value and we just want to determinate if it's possible or not to sum $C$.

## Infinitely many coins and boolean decicion

The solution involves DP. The instance of our DP will be just the current value we are trying to decide if it's possible.
So $DP(x)$ is `true` iff we can sum $x$.

The base cases are $x = 0$, that's always `true` and $x < 0$, that's always `false`.
For all $x$ with $0 < x \leq C$, $DP(x)$ is `true` only if we can use any of the coins in $S$ to get $x$. 
Therefore, if $S = \{ c_1, \ c_2, \cdots, \ c_k\}$, then we have this formula:
$$DP(x) = DP(x-c_1) \vee D(x-c_2) \vee \cdots \vee D(x-c_k)$$

That's easy to implement:

### Implementation
```cpp
int const N = 10e5;
bool DP[N];
int S[N];

// k is the number of coins
bool change(int C, int k) {
  for (int i = 1; i <= C; i++) DP[i] = false;
  DP[0] = true;

  for (int i = 1; i <= C; i++) {
    for (int j = 0; j < k && !DP[i]; j++) {
      if (i - S[j] < 0) continue;
      DP[i] = DP[i - S[j]];
      // As soon DP[i] become true, we leave the for
    }
  }

  return DP[C];
}
```

### Analysis

The time complexity is $O(C\cdot k)$ and space complexity is $O(C + k)$.

### Neps

One can test the code above in the problem [Véi, dá meu troco!](https://neps.academy/lesson/189) from Neps.

## Limited coins 

Now we still have a boolean decision, but we are given a limit of coins we can use. By now, this limit falls onto every coin. So if the limit is L, we cannot use more than L coins at all.

For instance, if set is $S = {1, 2}$, the limit is $L = 7$ and $C = 11$, we cannot use eleven coins of one but we can use five coins of two and one of one, because $5 + 1 = 6 \leq 7$.

### Solution

Now we need to add one dimension to our DP, because the number of coins used so far is important. So our array `DP` will be `DP[x][l]` where $x$ is the current value and $l$ is the number of coins used so far. 
Now we, if we are in the instance $(x, l)$, we'll use the value from $(x - c_i, \ l-1)$ and at the end, we need to return the conjuntion of $(C, l)$ for all $0 \leq l \leq L$.

Now we just need to think in the base cases.
Again, $x = 0$ is `true` for any $l$ and $x < 0$ is `false` for any $l$.
But another base case is when $l = 0$, that's always `false` since it's impossible to have change without any coins (except for $x = 0$).

That's try to implement that.

### Implementation
```cpp
int const N = 10e3;
bool DP[N][N];
int S[N];

// k is the number of coins
// L is the limit of coins we can use
bool change(int C, int k, int L) {
  for (int i = 1; i <= C; i++)
    for (int j = 0; j <= L; j++)
      DP[i][j] = false;

  for (int j = 0; j <= L; j++)
    DP[0][j] = true;

  for (int i = 1; i <= C; i++) {
    for (int I = 1; I <= L; I++) {
      for (int j = 0; j < k && !DP[i][I]; j++) {
        if (i - S[j] < 0) continue;
        DP[i][I] = DP[i - S[j]][I-1];
        // As soon DP[i] become true, we leave the for
      }
    }
  }

  for (int i = 0; i <= L; i++) if (DP[C][i]) return true;
  
  return false;
}
```

### Analysis

Again, the analysis is very simple, it's $O(C\cdot k \cdot L)$ in time and $O(C\cdot L + k)$ in space. 

### Neps

One can test the code above in the problem [Mano, tu me dá esse troco com menos de dez moedas!](https://neps.academy/lesson/188) from Neps.

## Finite number of coins

Now we have a multiset S and each coins can be used once.

### Solution

The solution is just like a 0-1 knapsack problem, we can order the coins and for each one decide if we want to use it or not.

### Implementation

```cpp
int const N = 10e5;
bool DP[N][N];
int S[N];

int K, C;

bool change(int c, int k) {
  if (c < 0 || k > K) return false;
  if (c == 0) return true;

  bool &d = DP[c][k];
  if (d == true) return d;

  return d = change(c, k+1) || change(c-S[k], k+1);
}

int main() {
  cin >> C >> K;
  for (int i = 0; i < K; i++) cin >> S[i];

  for (int i = 0; i <= C; i++) 
    for (int j = 0; j < k; j++)
      DP[i][j] = false;

  cout << change(C, 0) << endl;
  return 0;
}
```

### Analysis

The time complexty is $O(K\cdot N)$ in time and $O(K\cdot N + K)$ in space.

### URI

One can test the code above in the problem [Troco](https://www.urionlinejudge.com.br/judge/en/problems/view/2446) from URI Online Judge.

## Fewest Coins to make Change

How we have not a boolean evaluation of if it's possible to make change, but we want to how and minimum number of coins we need to use to make change. For instance, if $S = \{1, 2, 5\}$ and $C = 11$, then the output should be $3$ because that's the minimum amount of coins we can use to make $11$ ($5 + 5 + 1$).

That looks like a greedy problem (pick always the greater possible coin), but that's not since we can have exemples like
$S = \{2, 5, 11\}$ with $C = 12$. Picking 11 makes it impossible to make change, because there's no one's coin.

### Solution

Again, we'll DP to solve this problem dividing the instances by the current sum ($DP(x) =$ the minimum amount of coins I use to make $x$).

The base case again is $x = 0$ because I need no coins to make change. So $DP(0) = 0$.
For any other $x$ I'll be picking the minimum of all $DP(x - c_i)$ for all $c_i$ in $S$ and after picking the minimum, I should add one to my answer, because I used one more coin.

### Implementation
```cpp
int const N = 10e5;
int DP[N];
int S[N];

int change(int C, int k) {
  for (int i = 0; i <= C; i++) DP[i] = C + 1; //placeholder
  
  DP[0] = 0; //base case
  // other cases:
  for (int i = 1; i  <= C; i++) 
    for (int j = 0; j < k; j++) 
      if (i - S[j] >= 0) // if it's a legal value
        DP[i] = min(DP[i - S[j]] + 1, DP[i]);
    
  return DP[C];
} 

int main() {
  int C, k;
  cin >> C >> k;
  for (int i = 0; i < k; i++) cin >> S[i];
  int ans = change(C, k);
  if (ans == C + 1) ans = -1; // If it's not possible to make change
  cout << ans << endl;
  return 0;
}
```

### Path recover

If we want to recover the path from our solution (i.e., know what coins do we use to make change) we just need to start at C in our `DP` array and for all possible $c_i \in S$ we find the minimum value of `DP[ci]` and move our pointer to that value and do the same thing until reache `DP[0]`, where we stop. While that, we recover every value.

For instance, for $S = \{ 1, 2, 5\}$ and $C = 11$, our array will be:
`index_0__1__2__3__4__5__6__7__8__9_10_11`
`DP = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]`

Starting in index 11, we check what is the minumim value that we can go, so we'll test with all coins.
For one's coins we have $DP[11 - 1] = 2$
For two's coins we have $DP[11 - 2] = 3$
For five's coins we have $DP[11 - 5] = 2$

So we can go to both 10 and 6. (As sum is commutative, the result will be the same)
Suposse we go to 10 picking one's coin. So our solution set is now $A = \{1\}$.

Now we do the same for 10:
For one's coins we have $DP[10 - 1] = 3$
For two's coins we have $DP[10 - 2] = 3$
For five's coins we have $DP[10 - 5] = 1$

So we need to go to 5 using a five's coins. $A = \{1, 5\}$
Same for 5:
For one's coins we have $DP[5 - 1] = 2$
For two's coins we have $DP[5 - 2] = 2$
For five's coins we have $DP[5 - 5] = 0$

So we need to use again a five's coins and as we reached 0, we stop with solution set $A = \{1, 5, 5\}$

This algorithm runs in $\Theta(DP[C])$. Can you see why?

### Analysis

The time complexity is $O(C\cdot k)$ and the time complexity is $O(C + k)$.

## Total Unique Ways to Make Change

Now we have a counting problem and will solve this problem in a similar way that we solved the other problems: doing a DP with intance in the current sum.
The new thing is that we'll add a new dimension to your DP meaning the last coin we used. 
So we'll have one dimension for the amount and another for the coins I'm allowed to use.

### Exemples

* $S =\{1, 2, 5\} \ C = 5$ then there are $4$ ways:
  * $5$
  * $2+2+1$
  * $2+1+1+1$
  * $1+1+1+1+1$
* $S = \{2\} \ C = 3$ then there is no way.

Explaning the DP instances in $S =\{1, 2, 5\} \ C = 5$.

`DP[i][0]` is the number of ways to make $i$ with no coins (the first 0 coins in your set $S$).
`DP[i][1]` is the number of ways to make $i$ with just the first coins (the 1 coin).
`DP[i][2]` is the number of ways to make $i$ with the first 2 coins in your set (coins 1 and 2).
And `DP[i][3]` is the number of ways to make $i$ with the first 3 coins in your set (coins 1, 2 and 5).

### Solving

For the base cases we'll be having two base cases:
* $DP(0)(i)$ for any $i$ will be always 1. Because there's always one way of doing no change.
* $DP(i)(0)$ for any $i$ except $0$ will always be $0$. Because we want to make $i$ with no coins (that's impossible).

For any other case, we need to consider just the last coins we're using. So for $DP(i)(j)$ the new coin we're adding to your set of coins is the $j$-th coin. The options we have is including $j$-th coin in the sum $i-j$ or don't use this coin because we already have some ways of summing $i$ without it.
So the relation will be: $$DP(i)(j) = DP(i-S[j])(j) + DP(i)(j-1)$$

### Implementation