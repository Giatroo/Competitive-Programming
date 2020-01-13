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

const ll N = 200100;
ll arr[N];
ll t[4*N];
ll n;
string s;
ll a, b;
ll num;

void build(ll i, ll l, ll r) {
  if (l == r) t[i] = arr[l];
  else {
    ll m = l + (r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    t[i] = t[2*i] + t[2*i+1];
  }
}

void update(ll i, ll l, ll r, ll p, ll x) {
  if (l == r) t[i] = x;
  else {
    ll m = l + (r-l)/2;
    if (p <= m) update(2*i, l, m, p, x);
    else update(2*i+1, m+1, r, p, x);
    t[i] = t[2*i] + t[2*i+1];
  }
}

ll querry(ll i, ll l, ll r, ll ql, ll qr) {
  if (ql <= l && r <= qr) return t[i];
  if (qr < l || r < ql) return 0;

  ll m = l + (r-l)/2;
  return querry(2*i, l, m, ql, qr) +
         querry(2*i+1, m+1, r, ql, qr);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%lld", &n);

  num = 1;
  while (n != 0) {
    forai (i, n) scanf("%lld", arr+i);
    build(1, 1, n);

    printf("Case %lld:\n", num++);
    while (true) {
      cin >> s;
      if (s[0] == 'E') { break; }
      cin >> a >> b;
      if (s[0] == 'M') printf("%lld\n", querry(1, 1, n, a, b));
      else update(1, 1, n, a, b);
    }

    scanf("%lld", &n);
    if (n != 0) printf("\n");
  }

  return 0;
}
