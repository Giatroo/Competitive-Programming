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

ll n;
ll caixas[112][112];
ll memo[112][112];

ll f(ll i, ll j) {
  // printf("i = %lld j = %lld\n", i, j);
  if (j - i < 0) return 0;

  if (memo[i][j] == -1) {
    memo[i][j] = (caixas[j-i+1][j] - caixas[j-i+1][i-1]);
    memo[i][j] += min(f(i, j-1), f(i+1, j));
  }
  // printf("memo[%lld][%lld] = %lld\n", i, j, memo[i][j]);
  return memo[i][j];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  forai (i, n) forai (j, n) {
    get1(caixas[i][j]);
    caixas[i][j] += caixas[i][j-1];
  }
  fora (i, n) caixas[i][0] = 0;
  fora (i, n + 2) fora (j, n + 2) memo[i][j] = -1;

  // forai (i, n) {
  //   forai (j, n)
  //     cout1(caixas[i][j]) << " ";
  //   cout << endl;
  // }

  cout1e(f(1, n));

  return 0;
}
