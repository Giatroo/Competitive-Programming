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

ll n;
pll p;
vector<ll> a;

ll dist(pll pt) {
  return pt.f*pt.f + pt.s*pt.s;
}

ll inv(vector<ll> &v) {
  ll ic = 0;
  if (v.size() == 1) return ic;

  vector<ll> u1, u2;
  for (ll i = 0; i < v.size()/2; i++) u1.pb(v[i]);
  for (ll i = v.size()/2; i < v.size(); i++) u2.pb(v[i]);

  ll ini1, ini2;
  ini1 = ini2 = 0;

  ic += inv(u1);
  ic += inv(u2);
  u1.pb(MINF);
  u2.pb(MINF);

  for (ll i = 0; i < v.size(); i++) {
    if (u1[ini1] > u2[ini2]) v[i] = u1[ini1++];
    else {
      v[i] = u2[ini2++];
      ic += u1.size() - ini1 - 1;
    }
  }

  // cout << "u1 = ";
  // fora (i, u1.size()) cout << u1[i] << " ";
  // cout << endl;
  // cout << "u2 = ";
  // fora (i, u2.size()) cout << u2[i] << " ";
  // cout << endl;
  // cout << "Retornando " << ic << endl;
  return ic;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora (i, n) { get2(p.f, p.s); a.pb(dist(p)); }

  // fora (i, n) cout << a[i] << " ";
  // cout << endl;

  cout << inv(a) << endl;

  return 0;
}
