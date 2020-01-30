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

ll c, k, p, n, q, a[112345];
ll t[412345];

void build(ll l, ll r, ll i) {
  if (l == r) t[i] = a[l];
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    t[i] = t[2*i] + t[2*i+1];
  }
}

void update(ll l, ll r, ll i, ll p, ll v) {
  if (l == r) t[i] = v;
  else {
    ll m = l + (r-l)/2;
    if (p <= m) update(l, m, 2*i, p, v);
    else update(m+1, r, 2*i+1, p, v);
    t[i] = t[2*i] + t[2*i+1];
  }
}

ll query(ll l, ll r, ll i, ll ql, ll qr) {
  if (ql <= l && r <= qr) return t[i];
  if (qr < l || r < ql) return 0;
  ll m = l + (r-l)/2;
  return query(l, m, 2*i, ql, qr) +
         query(m+1, r, 2*i+1, ql, qr);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, q);
  forai (i, n) get1(a[i]);
  build(1, n, 1);
  fora (i, q) {
    get1(c);
    if (c == 0) {
      get2(k, p);
      update(1, n, 1, k, p);
    } else {
      get1(k);
      cout1e(query(1, n, 1, 1, k));
    }
  }

  return 0;
}
