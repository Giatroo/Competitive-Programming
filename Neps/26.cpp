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

ll l, c;
char m[112][112];
pll ini;
pll mov[4];

bool inside(pll pt) {
  return pt.f >= 0 && pt.f < l && pt.s >= 0 && pt.s < c;
}

pll bfs() {
  stack<pll> st;
  st.push(ini);
  m[ini.f][ini.s] = '.';

  while (!st.empty()) {
    ini = st.top(); st.pop();
    bool last = true;
    fora (i, 4) {
      pll pt = mk(ini.f + mov[i].f, ini.s + mov[i].s);
      if (inside(pt) && m[pt.f][pt.s] == 'H') {
        st.push(pt);
        m[pt.f][pt.s] = '.';
        last = false;
      }
    }
    if (last) return ini;
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(1, 0);
  mov[1] = mk(0, 1);
  mov[2] = mk(-1, 0);
  mov[3] = mk(0, -1);
  get2(l, c);
  fora (i, l) fora (j, c)
  {
    get1(m[i][j]);
    if (m[i][j] == 'o') ini = mk(i, j);
  }

  pll pt = bfs();
  cout2e(pt.f+1, pt.s+1);

  return 0;
}
