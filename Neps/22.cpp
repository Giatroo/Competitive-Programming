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

int t[112][112];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  fora(i, n)
    fora(j, n)
      cin >> t[i][j];

  fora(i, n)
    fora(j, n)
      if(t[i][j] == 9)
        t[i][j] = (t[i-1][j] + t[i-1][j-1] + t[i][j-1] >= 2) ? 0 : 1;
  cout << t[n-1][n-1] << endl;

  return 0;
}
