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

ll n, q;
bool m[3][112345];
pll mov[8];
ll prob;
pll pt;

bool inside(pll p) {
  return p.f >= 1 && p.f <= 2 && p.s >= 1 && p.s <= n;
}

bool lava(pll p) {
  return m[p.f][p.s];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(0, 1);
  mov[1] = mk(1, 0);
  mov[2] = mk(0, -1);
  mov[3] = mk(-1, 0);
  mov[4] = mk(1, 1);
  mov[5] = mk(-1, -1);
  mov[6] = mk(-1, 1);
  mov[7] = mk(1, -1);
  get2(n, q);
  forai (i, n) m[1][i] = m[2][i] = false;
  prob = 0;

  fora (i, q) {
    get2(pt.f, pt.s);
    ll inc = (lava(pt)) ? -1 : 1;

    fora (k, 8) {
      pll neighbor = mk(pt.f + mov[k].f, pt.s + mov[k].s);
      // cout3e("looking", neighbor.f, neighbor.s);
      // if (inside(neighbor)) cout1e("inside");
      // if (lava(neighbor)) cout1e("lava");
      if (inside(neighbor) && lava(neighbor)) {
        if (!(abs(neighbor.s - pt.s) == 1 && pt.f == neighbor.f)) {
          prob += inc;
          // cout3e("incrementing in", neighbor.f, neighbor.s);
          // cout1e(prob);
        }
      }
    }
    m[pt.f][pt.s] = (lava(pt)) ? false : true;

    cout << ((prob == 0) ? "Yes" : "No") << endl;
  }

  return 0;
}
