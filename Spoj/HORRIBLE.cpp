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

ll n, c, o, p, q, v, tot;
ll a[112345];
ll t[412345];
ll lz[412435];

void build(ll l, ll r, ll i) {
  if (l == r) t[i] = a[l];
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    t[i] = t[2*i] + t[2*i+1];
  }
  lz[i] = 0;
}

void push(ll l, ll r, ll i) {
  if (lz[i]) {
    t[i] += lz[i] * (r-l+1);
    if (l != r) {
      lz[2*i] += lz[i];
      lz[2*i+1] += lz[i];
    }
    lz[i] = 0;
  }
}

void update(ll l, ll r, ll i, ll ql, ll qr, ll x) {
  push(l, r, i);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    lz[i] += x;
    push(l, r, i);
  } else {
    ll m = l + (r-l)/2;
    update(l, m, 2*i, ql, qr, x);
    update(m+1, r, 2*i+1, ql, qr, x);
    t[i] = t[2*i] + t[2*i+1];
  }
}

ll query(ll l, ll r, ll i, ll ql, ll qr) {
  push(l, r, i);
  if (ql <= l && r <= qr) return t[i];
  if (qr < l || r < ql) return 0;
  ll m = (l+r)/2;
  return query(l, m, 2*i, ql, qr) + query(m+1, r, 2*i+1, ql, qr);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(tot);
  fora (k, tot) {
    get2(n, c);
    fora (i, n + 3) a[i] = 0;
    build(1, n, 1);
    fora (i, c) {
      get1(o);
      if (o == 0) {
        get3(p, q, v);
        update(1, n, 1, p, q, v);
      } else {
        get2(p, q);
        cout1e(query(1, n, 1, p, q));
      }
    }
  }

  return 0;
}
