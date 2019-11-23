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

ll c, t, aux;
set<ll> s;

int main(int argc, char const *argv[]) {
  cin >> c;
  t = 0;
  fora(i, c)
  {
    cin >> aux;
    if(s.find(aux) == s.end())
    {
      t += 2;
      s.insert(aux);
    } else
      s.erase(aux);
  }

  cout << t << endl;

  return 0;
}
