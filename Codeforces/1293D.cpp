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

ll xz, yz, ax, ay, bx, by;
ll xs, ys, t;

vector<pll> pts;
ll dist, mindist;
ll num;

ll d(pll p1, pll p2) {
  return abs(p1.f - p2.f) + abs(p1.s - p2.s);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get3(xz, yz, ax);
  get3(ay, bx, by);
  get3(xs, ys, t);

  mindist = INF;
  pll my = mk(xs, ys);
  pll pt = mk(xz, yz);

  while (d(pt, my) < mindist) {
    pts.pb(pt);
    mindist = d(pt, my);
    pt.f = ax*pt.f + bx;
    pt.s = ay*pt.s + by;
  }

  pll lp;
  lp.f = pt.f;
  lp.s = pt.s;

  num = 0;
  while (true) {
    pt = pts.back();
    pts.pop_back();
    // cout3e("Analysing point", pt.f, pt.s);
    if (d(pt, my) > t) break;
    else {
      num++;
      // cout3e("collecting", pt.f, pt.s);
      t -= d(pt, my);
      // cout2e("time left is", t);
      my.f = pt.f;
      my.s = pt.s;
    }

    if (pts.empty()) {
      pts.pb(lp);
      lp.f = ax*lp.f + bx;
      lp.s = ay*lp.s + by;
    }
  }

  cout1e(num);

  return 0;
}
