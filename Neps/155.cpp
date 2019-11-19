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
  int n;
  int aux;
  int a2, a3, a4;
  cin >> n;
  a2 = a3 = a4 = 0;
  fora(i, n)
  {
    cin >> aux;
    if(aux % 2 == 0) a2++;
    if(aux % 3 == 0) a3++;
    if(aux % 4 == 0) a4++;
  }

  cout << a2 << endl << a3 << endl << a4 << endl;

  return 0;
}
