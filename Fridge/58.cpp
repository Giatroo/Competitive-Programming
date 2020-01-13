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

ll n;
ll h[112345];
ll l, r;
ll num;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora (i, n) get1(h[i]);

  l = num = 0;
  if (h[0] <= h[1])
    while (h[l] <= h[l+1]) l++;


  for (ll a = l+1; a < n; a++) {
    if (h[a] >= h[l]) {
      num += (a-l-1);
      cout << "Somando " << a-l-1 << " no ponto " << a << endl;
      l = a;
    }
  }

  if (l != n-1) {
    r = n-1;
    if (h[n-1] <= h[n-2])
      while (h[r] <= h[r-1]) r--;
    cout << "l = " << l << " r = " << r << endl;
    if (l != r) num += r - l - 1;
  }

  cout1e(num);


  return 0;
}
