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