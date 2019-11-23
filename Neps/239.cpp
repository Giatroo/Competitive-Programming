#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

int main(int argc, char const *argv[]) {
  ll n, d, c, imax;
  lld max;
  max = 0;
  cin >> n;
  fora(i, n)
  {
    cin >> d >> c;
    if(d == 0 && max == 0) imax = i;
    else if(c == 0 && max == 0) max = 1, imax = i;
    else if(c * log(d) > max) max = c*log(d), imax = i;
  }

  cout << imax << endl;

  return 0;
}
