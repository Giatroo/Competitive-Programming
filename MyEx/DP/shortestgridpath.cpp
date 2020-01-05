#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define INF LLONG_MAX

using namespace std;

// Problem: Given a number n and a n by n grid of numbers,
// find the path that goes from (1,1) to (n,n) moving only
// right or down that minimizes the sum through the path

ll n; // n <= 10^3
ll grid[1123][1123]; // 1-indexed
ll dp[1123][1123]; // the dynamic programing table

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  forai (i, n) forai (j, n) get1(grid[i][j]);


  // Ideia: the minumum path P to a point (i, j) is
  // the minumum between P(i-1, j) and P(i, j-1) plus
  // the value of (i, j)

  //Base case is the up-left corner
  fora (i, n + 3) dp[i][0] = INF;
  fora (i, n + 3) dp[0][i] = INF;
  dp[0][1] = dp[1][0] = 0;

  forai (i, n)
    forai (j, n)
      dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

  cout1e(dp[n][n]);
  forai (i, n) {
    forai (j, n)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  
  return 0;
}
