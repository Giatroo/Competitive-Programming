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
  int d1, d2, h1, h2, m1, m2;
  ll t1, t2;

  cin >> d1 >> h1 >> m1 >> d2 >> h2 >> m2;
  t1 = t2 = 0;
  t1 += d1*24*60*60;
  t1 += h1*60*60;
  t1 += m1*60;
  t2 += d2*24*60*60;
  t2 += h2*60*60;
  t2 += m2*60;

  cout << abs(t1 - t2) << endl;

  return 0;
}
