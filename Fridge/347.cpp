#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
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

ll n, q, k, a, b, o;
ll seg[412345], lz[412345], arr[112345];

void build(ll l, ll r, ll i) {
  if (l == r)
    seg[i] = arr[l];
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    seg[i] = seg[2*i] + seg[2*i+1];
  }
  lz[i] = 0;
}

void push(ll l, ll r, ll i) {
  if (lz[i] != 0) {
    seg[i] = lz[i]*(r-l+1);
    if (l != r)
      lz[2*i] = lz[2*i+1] = lz[i];
    lz[i] = 0;
  }
}

void update(ll l, ll r, ll i, ll ql, ll qr, ll x) {
  push(l, r, i);
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    lz[i] = x; push(l, r, i);
  } else {
    ll m = l + (r-l)/2;
    update(l, m, 2*i, ql, qr, x);
    update(m+1, r, 2*i+1, ql, qr, x);
    seg[i] = seg[2*i] + seg[2*i+1];
  }
}

int query(ll l, ll r, ll i, ll ql, ll qr) {
  push(l, r, i);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return seg[i];
  ll m = l + (r-l)/2;
  return query(l, m, 2*i, ql, qr) + query(m+1, r, 2*i+1, ql, qr);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, q);
  forai (i, n) get1(arr[i]);
  build(1, n, 1);

  // cout << endl;
  // fora (i, 4*n) {
  //   cout3e(i, seg[i], lz[i]);
  // }
  // cout << endl;

  fora (i, q) {
    cin >> o;
    if (o == 1) {
      cin >> a >> b >> k;
      update(1, n, 1, a, b, k);
    } else {
      cin >> a >> b;
      cout << query(1, n, 1, a, b) << endl;
    }

    // cout << endl;
    // fora (i, 4*n) {
    //   cout3e(i, seg[i], lz[i]);
    // }
    // cout << endl;
  }

  return 0;
}
