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
  ll v[3], sum;
  sum = 0;
  cin >> v[0] >> v[1] >> v[2];
  fora(i, 3)
    if(v[i] % 2 == 0 || v[i] % 5 == 0) sum++;
  cout << sum << endl;
  return 0;
}
