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

ll n;
int b[50];
int m;

int main(int argc, char const *argv[]) {
  cin >> n;
  m = 0;

  if(n == 0){
    cout << 0 << endl;
    return 0;
  }

  while(n > 0)
  {
    b[m++] = n % 2;
    n /= 2;
  }

  reverse(b, b+m);
  fora(i, m)
    cout << b[i];
  cout << endl;

  return 0;
}
