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

ll t[4*20], a[20];

void build(ll l, ll r, ll i) {
  if (l == r) t[i] = a[l];
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    t[i] = t[2*i] + t[2*i+1];
  }
}

void query(ll l, ll r, ll i) {
  if (l == r) return;

  if (t[i] == 2 && t[2*i] != 2 && t[2*i+1] != 2) {
    if (i == 1) cout1e("final");
    else if (i < 4) cout1e("semifinal");
    else if (i < 8) cout1e("quartas");
    else if (i < 16) cout1e("oitavas");
    return;
  } else {
    ll m = l + (r-l)/2;
    query(l, m, 2*i);
    query(m+1, r, 2*i+1);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  forai (i, 16) a[i] = 0;
  get1(n);
  a[n]++;
  get1(n);
  a[n]++;
  build(1, 16, 1);
  // forai (i, 32) cout2e(i, t[i]);
  query(1, 16, 1);

  return 0;
}
