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

ll m;
vector<ll> w;
vector<ll> used;
ll lu;
ll l, r;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string in;
  get1(in);
  fora (i, 10) if (in[i] == '1') w.pb(i+1);
  get1(m);
  l = r = 0;

  if (w.empty()) { cout1e("NO"); return 0; }
  lu = w[0];
  l += w[0];
  used.pb(lu);

  forai (i, m-1) {
    ll next = 0;
    forita (it, w) {
      if (*it == lu) continue;
      if ((i % 2 == 0 && l + *it > r) ||
          (i % 2 == 1 && r + *it > l)) {
        next = *it; break;
      }
    }
    if (next == 0) { cout1e("NO"); return 0; }
    lu = next;
    if (i % 2 == 0) l += next;
    else r += next;
    used.pb(lu);
  }

  cout1e("YES");
  forita (it, used) cout1(*it) << " ";
  cout << endl;




  return 0;
}
