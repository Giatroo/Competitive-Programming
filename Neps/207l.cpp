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
#define coutp(a, b) cout << (a) << " " << (b)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll a, v;
ll x, y;
pair<ll, ll> aero[11234];
ll n;
ll maxi;

bool cmp(pair<ll, ll> p, pair<ll, ll> q) {
  if (p.f == q.f) return p.s < q.s;
  return p.f > q.f;
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> v;
  n = 1;
  while (a*v != 0) {
    fora(i, a+1) { aero[i].f = 0; aero[i].s = i; }
    fora(i, v) {
      cin >> x >> y;
      aero[x].f++;
      aero[y].f++;
    }

    cout << "Teste " << n++ << endl;
    // forai(i, a) { coutp(aero[i].f, aero[i].s) << endl; }
    // cout << endl;

    sort(aero + 1, aero + a + 1, cmp);
    maxi = aero[1].f;

    // forai(i, a) { coutp(aero[i].f, aero[i].s) << endl; }
    // cout << endl;

    ll i = 1;
    while(aero[i].f == maxi) {
      cout << aero[i++].s << " ";
    }
    cout << endl;

    cin >> a >> v;
  }

  return 0;
}
