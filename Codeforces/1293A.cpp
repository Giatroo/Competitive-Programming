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

ll n, s, k, t;
vector<ll> a;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  fora (j, t) {
    get3(n, s, k);
    a.resize(k);
    fora (i, k) get1(a[i]);
    sortvector(a);

    ll ind = lower_bound(a.begin(), a.end(), s) - a.begin();
    ll l, r;
    l = r = INF;

    if (a[ind] != s) { cout1e(0); continue; }

    // cout2e(ind, a[ind]);

    ll i;
    for (i = ind; i >= 0; i--) {
      if (a[i] != s - (ind - i)) {
        l = (ind - i);
        break;
      }
    }
    // cout2e("i = ", i);
    if (a[i+1] == 1) l = INF;
    else l = (ind - i);

    for (i = ind; i < a.size(); i++) {
      if (a[i] != s + (i - ind)) {
        r = (i - ind);
        break;
      }
    }
    // cout2e("i = ", i);
    if (a[i-1] == n) r = INF;
    else r = (i-ind);


    // cout1e(l);
    // cout1e(r);
    cout1e(min(l, r));

    a.clear();
  }

  return 0;
}
