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
#define M 1000000007

using namespace std;

ll n, q;
ll a[51][51];
ll li, ci, lf, cf;
ll tot;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  tot = 0;
  get1(n);
  fora (i, n) fora (j, n) get1(a[i][j]);
  get1(q);
  fora (i, q) {
    get2(li, ci);
    get2(lf, cf);
    li--; lf--; ci--; cf--;
    for (ll c = li; c <= lf; c++)
      for (ll b = ci; b <= cf; b++)
        if (a[c][b] > 0) {
          tot += a[c][b]; a[c][b] = 0;
        }
  }

  // fora (i, n) {
  //   fora (j, n) cout1(a[i][j]) << " ";
  //   cout << endl;
  // }
  // cout << endl << endl;

  cout1e(tot);

  return 0;
}
