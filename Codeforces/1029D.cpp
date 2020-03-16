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
#define cout2e(a, b) cout << (a) << (b) << endl
#define cout3e(a, b, c) cout << (a) << (b) << (c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007
using namespace std;
// ===================================================== //

ll n, a[212345], k;
ll ans;
vector<ll> digit[11];
ll tenToIModK[11];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ans = 0;
  scanf("%d%d", &n, &k);
  ll d;
  fora (i, n) {
    scanf("%d", a+i);
    d = ceil(log10(a[i]+1));
    digit[d].pb(a[i]%k);
  }

  forai (i, 10) sortvector(digit[i]);

  tenToIModK[0] = 1;
  forai (i, 10) tenToIModK[i] = (tenToIModK[i-1]*10)%k;

  ll amod, j;
  fora (i, n) { // iterating on i
    amod = a[i] % k;
    forai (db, 10) { // iterating on digits of j
      j = k - ((amod * tenToIModK[db])%k);
      if (j == k) j = 0;

      if (j == amod && ceil(log10(a[i]+1)) == db)
        ans--;


      auto lb = lower_bound(digit[db].begin(), digit[db].end(), j);
      auto ub = upper_bound(digit[db].begin(), digit[db].end(), j);
      ans += ub - lb;
    }
  }

  cout1e(ans);

  return 0;
}
