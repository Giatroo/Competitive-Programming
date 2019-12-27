#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n;
ll a[1123456];

ll rotationBinSearch(ll l, ll r) {
  ll m;
  ll ans = 0;
  while (l <= r) {
    m = l + (r - l) / 2;
    printf("l = %lld m = %lld r = %lld\n", l, m, r);
    if (a[m] > a[n-1]) l = m + 1;
    else ans = m, r = m - 1;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fora(i, n) cin >> a[i];
  printf("%lld\n", rotationBinSearch(0, n-1));


  return 0;
}
