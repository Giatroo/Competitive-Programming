#include <bits/stdc++.h>
typedef long long int ll;
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

double a, b, c;
double aux;

int main(int argc, char const *argv[]) {
  int m, n;
  a = b = c = 0;
  cin >> m >> n;
  fora(i, m)
  {
      cin >> aux;
      a += pow(2, -(i+1)) * aux;
  }
  fora(i, n)
  {
      cin >> aux;
      b += pow(2, -(i+1)) * aux;
  }

  c = a+b;

  //printf("a = %lf b = %lf c = %lf\n", a, b, c);

  for(int i = 0; c > 0.000001; i++)
  {
    aux = pow(2, -(i+1));
    if(c - aux >= 0)
    {
      cout << 1 << " ";
      c -= aux;
    } else
    {
      cout << 0 << " ";
    }
  }
  cout << endl;

  return 0;
}
