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

ll c, n, k;
ll price[112]; //1-indexed
ll memo[112][112][112];

//parcial k, parcial n, package i'm considering
ll f(ll pk, ll pn, ll pack) {
  if (pk < 0 || pn > n || pack > k) return 1112345; //inf
  if (pk == 0) return 0;


  if (memo[pk][pn][pack] == -1) {
    ll a = INF;
    if (price[pack] >= 0)
      a = price[pack] + f(pk - pack, pn + 1, pack);
    ll b = f(pk, pn, pack + 1);

    // cout3e(pk, pn, pack);
    // cout << "a, b " << a << " " << b << endl;
    memo[pk][pn][pack] = min(a, b);
  }
  return memo[pk][pn][pack];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(c);
  fora (q, c) {
    get2(n, k);
    forai (i, k) get1(price[i]);
    fora(i, k + 3) fora(j, n + 3) fora(h, k + 3)
      memo[i][j][h] = -1;

    // cout << "ola" << endl;
    ll ans = f(k, 0, 1);
    if (ans < 0 || ans >= 1112345)
      cout1e(-1);
    else
      cout1e(ans);
  }

  return 0;
}
