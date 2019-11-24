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
#define forita(c) for(auto it = c.begin(); it != c.end(); it++)

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
  int n;
  ll f2, f1, f;

  f2 = 0;
  f1 = 1;

  cin >> n;

  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }

  cout << 0 << " " << 1 << " ";

  for(int i = 2; i < n; i++)
  {
    f = f1 + f2;
    f2 = f1;
    f1 = f;
    cout << f << " ";
  }
  cout << endl;

  return 0;
}
