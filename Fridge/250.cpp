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
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n;
ll t, d;
vector<pair<ll, ll>> p; //pedidos: dia de entrega, tempo confecção

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.f * a.s == b.f * b.s) return a.f < b.f;
  else return a.f * a.s < b.f * b.s;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fora(i, n) {
    cin >> t >> d;
    p.pb(mp(d, t));
  }

  sortvectorby(p, cmp);

  /*fora(i, n) {
    cout << p[i].f << " " << p[i].s << endl;
  }*/

  t = d = 0;
  fora(i, n) {
    if( max(0, d + p[i].s - p[i].f) > t) t = max(0, d + p[i].s - p[i].f);
    d += p[i].s;
  }

  cout << t << endl;

  return 0;
}
