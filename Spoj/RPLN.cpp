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

ll t, n, q, a, b;
ll arr[112345];
ll st[412345];

void build(ll l, ll r, ll i) {
  if (l == r) st[i] = arr[l];
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    st[i] = min(st[2*i], st[2*i+1]);
  }
}

ll query(ll l, ll r, ll i, ll ql, ll qr) {
  if (ql <= l && r <= qr) return st[i];
  if (l > qr || ql > r) return INF;
  ll m = l + (r-l)/2;
  return min(query(l, m, 2*i, ql, qr), query(m+1, r, 2*i+1, ql, qr));
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);

  forai (test, t) {
    get2(n, q);
    forai (i, n) get1(arr[i]);
    build(1, n, 1);

    // forai (i, 2*n) cout1e(st[i]);

    cout << "Scenario #" << test << ":" << endl;
    fora (i, q) {
      get2(a, b);
      cout1e(query(1, n, 1, a, b));
    }
  }

  return 0;
}
