#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef std::pair<ll, ll> pll;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define cout1e(a) cout << (a) << endl
#define cout2e(a, b) cout << (a) << " " << (b) << endl
#define cout3e(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define cout4e(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007
using namespace std;
// ===================================================== //

ll const N = 212345;

ll n, ans;
ll a[N], b[N];
vector<ll> c;


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n); c.resize(n);
  fora (i, n) get1(a[i]);
  fora (i, n) get1(b[i]);
  fora (i, n) c[i] = a[i] - b[i];

  sortvector(c);

  ll j;
  ans = 0;
  for (ll i = n-1; i > 0; i--) {
    if (c[i] <= 0) break;
    j = lower_bound(c.begin(), c.end(), -c[i]+1) - c.begin();
    // cout2e(i, j);
    ans += i-j;
  }

  cout1e(ans);


  return 0;
}
