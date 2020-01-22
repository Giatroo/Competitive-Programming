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
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

ll p, n;
ll dp[2123][2123];
ll v[2123], g[2123];

ll f(ll cur, ll wei) {
  if (wei < 0) return MINF;
  if (cur == n) return 0;

  if (dp[cur][wei] != -1) return dp[cur][wei];

  ll pega = f(cur+1, wei-g[cur]) + v[cur];
  ll npega = f(cur+1, wei);

  return dp[cur][wei] = max(pega, npega);
}

vector<ll> ans;

void path(ll cur, ll wei) {
  if (cur == n) return;

  ll pega = f(cur+1, wei-g[cur]) + v[cur];
  ll npega = f(cur+1, wei);

  if (pega > npega) {
    ans.pb(cur);
    path(cur+1, wei-g[cur]);
  } else {
    path(cur+1, wei);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(p, n);

  fora (i, n) get2(g[i], v[i]);

  fora (i, n+2)
    fora (j, p+2)
      dp[i][j] = -1;

  cout1e(f(0, p));
  // path(0, p);
  // forita (it, ans) cout << *it << " ";
  // cout << endl;

  return 0;
}
