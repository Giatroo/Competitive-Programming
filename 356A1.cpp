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

ll seg[1212345];
ll n, m;

void init(ll l, ll r, ll i) {
  if (l == r) seg[i] = delta[i] = 0;
  else {
    ll m = l + (r-l)/2;
    init(l, m, 2*i);
    init(m+1, r, 2*i+1);
    seg[i] = delta[i] = 0;
  }
}

void update(ll l, ll r, ll i, ll ql, ll qr, ll x) {
  if (l > qr || r < ql) return;
  if (ql <= l && r <= qr) {
    if (seg[i] == 0) seg[i] = x;
  }
  else {
    ll m = l + (r-l)/2;
    update(l, m, 2*i, ql, qr, x);
    update(m+1, r, 2*i+1, ql, qr, x);
  }
}

/*void traverse(ll l, ll r, ll i) {
  push(l, r, i);
  if (l < r) {
    ll m = l + (r-l)/2;
    traverse(l, m, 2*i);
    traverse(m+1, r, 2*i+1);
  } else if (l == r) {
    cout << seg[i] << " ";
  }
}*/

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  init(1, n, 1);
  ll a, b, x;
  fora (i, m) {
    get3(a, b, x);
    if (x-1-a >= 1)
      update(1, n, 1, a, x-1, x);
    if (b - x -1 >= 1)
      update(1, n, 1, x+1, b, x);
  }


  cout << endl;
  return 0;
}
