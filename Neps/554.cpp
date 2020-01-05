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

int K[1123]; //usado de 1 a k inclusos

int main(int argc, char const *argv[]) {
  ll n, k, aux, mini;
  cin >> n >> k;

  forai(i, k)
    K[i] = 0;

  fora(i, n)
  {
    cin >> aux;
    K[aux]++;
  }

  mini = INT_MAX;
  forai(i, k)
    mini = min(mini, K[i]);

  cout << mini << endl;

  return 0;
}
