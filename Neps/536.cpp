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
vector<ll> v;

ll ic(vector<ll> &u) {
  ll inv;
  vector<ll> u1, u2;

  if (u.size() == 1) return 0;

  ll i;
  for (i = 0; i < u.size()/2; i++) u1.pb(u[i]);
  for (; i < u.size(); i++) u2.pb(u[i]);

  inv = ic(u1);
  inv += ic(u2);

  u1.pb(INF);
  u2.pb(INF);

  ll ini1, ini2;
  ini1 = ini2 = 0;

  fora (i, u.size()) {
    if (u1[ini1] < u2[ini2]) u[i] = u1[ini1++];
    else {
      u[i] = u2[ini2++];
      inv += u1.size() - 1 - ini1;
    }
  }
  return inv;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  v.resize(n);
  fora (i, n) get1(v[i]);
  cout1e(ic(v));

  return 0;
}
