#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mk make_pair
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

ll n, m;
ll toca[1123][1123];
pair<ll, ll> ini;
pair<ll,ll> mov[4];

int dfs(pair<ll, ll> fonte) {
  stack<pair<ll, ll>> s;
  s.push(fonte);
  toca[fonte.f][fonte.s] = 1;

  while (!s.empty()) {
    fonte = s.top();
    s.pop();

    fora(i, 4) {
      if (toca[fonte.f + mov[i].f][fonte.s + mov[i].s] == -1) {
        s.push(mk(fonte.f + mov[i].f, fonte.s + mov[i].s));
        toca[fonte.f + mov[i].f][fonte.s + mov[i].s] =
         toca[fonte.f][fonte.s] + 1;

      } else if (toca[fonte.f + mov[i].f][fonte.s + mov[i].s] == -3)
        return toca[fonte.f][fonte.s] + 1;

    }
  }

  return 1;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(0, 1);
  mov[1] = mk(0, -1);
  mov[2] = mk(1, 0);
  mov[3] = mk(-1, 0);

  cin >> n >> m;

  fora(i, n + 2) fora(j, m + 2) toca[i][j] = 0;

  forai(i, n) {
    forai(j, m) {
      get1(toca[i][j]);
      if (toca[i][j] == 2)
        ini = mk(i, j);
      toca[i][j] *= -1;
    }
  }

  cout << dfs(ini) << endl;

  return 0;
}
