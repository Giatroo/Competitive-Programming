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
// ===================================================== //

const int N = 1123456;

string s;
pair<pll, ll> seg[4*N]; // #'(', #')', #tot
ll m, n;
ll a, b;

void build(ll l, ll r, ll i) {
  if (l == r) {
    seg[i].f.f = (s[l-1] == '(') ? 1 : 0;
    seg[i].f.s = (s[l-1] == ')') ? 1 : 0;
    seg[i].s = 0;
  } else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);

    ll mi = min(seg[2*i].f.f, seg[2*i+1].f.s);
    seg[i].s = seg[2*i].s + seg[2*i+1].s + 2*mi;
    seg[i].f.f = seg[2*i].f.f + seg[2*i+1].f.f - mi;
    seg[i].f.s = seg[2*i].f.s + seg[2*i+1].f.s - mi;
  }
}

pair<pll, ll> query(ll l, ll r, ll i, ll ql, ll qr) {
  if (qr < l || r < ql) return mk(mk(0, 0), 0);
  if (ql <= l && r <= qr) return seg[i];

  ll m = l + (r-l)/2;
  pair<pll, ll> left = query(l, m, 2*i, ql, qr);
  pair<pll, ll> right = query(m+1, r, 2*i+1, ql, qr);
  pair<pll, ll> ret;

  ll mi = min(left.f.f, right.f.s);
  ret.s = left.s + right.s + 2*mi;
  ret.f.f = left.f.f + right.f.f - mi;
  ret.f.s = left.f.s + right.f.s - mi;
  return ret;
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s; n = s.size();
  cin >> m;
  build(1, n, 1);

  // fora (i, 4*n) {
  //   cout << i << " " << seg[i].f.f << " "
  //        << seg[i].f.s << " " << seg[i].s << endl;
  // }

  fora (i, m) {
    cin >> a >> b;
    cout << query(1, n, 1, a, b).s << endl;
  }


  return 0;
}
