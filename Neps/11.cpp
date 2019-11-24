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

int m[51234][11];
ll col[11];
int n, aux;
ll p, nfat;

ll fat(ll n)
{
  if(n <= 1) return 1;
  else return n * fat(n-1);
}

int main(int argc, char const *argv[]) {
  cin >> n;
  nfat = fat(n);

  fora(i, n) col[i] = 0;

  fora(i, nfat-1) {
    fora(j, n) {
      cin >> m[i][j];
      col[j] += m[i][j];
    }
  }

  p = fat(n-1) * (n+1) * n / 2;
  fora(i, n)
    cout << p - col[i] << " ";
  cout << endl;

  return 0;
}
