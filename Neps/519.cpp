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
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define INF LLONG_MAX

using namespace std;

ll n, m;
pll cavalo;
pll mov[9];
set<pll> buraco;
ll t;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //up -> y+
  //left -> x+

  mov[0] = mk(0, 0);
  mov[1] = mk(1, 2);
  mov[2] = mk(2, 1);
  mov[3] = mk(2, -1);
  mov[4] = mk(1, -2);
  mov[5] = mk(-1, -2);
  mov[6] = mk(-2, -1);
  mov[7] = mk(-2, 1);
  mov[8] = mk(-1, 2);
  buraco.insert(mk(1, 3));
  buraco.insert(mk(2, 3));
  buraco.insert(mk(2, 5));
  buraco.insert(mk(5, 4));
  cavalo.f = 4; cavalo.s = 3;

  get1(n);
  t = 0;
  fora(i, n) {
    get1(m);
    cavalo.f += mov[m].f;
    cavalo.s += mov[m].s;
    t++;
    if (buraco.find(cavalo) != buraco.end()) break;
  }

  cout1e(t);

  return 0;
}
