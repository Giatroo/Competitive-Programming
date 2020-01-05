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
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

map<ll, ll> programas;
set<ll> novos;

int main(int argc, char const *argv[]) {
  ll c, n;
  ll aux1, aux2;

  cin >> c >> n;

  fora(i, c) {
    cin >> aux1 >> aux2;
    programas[aux1] = aux2;
  }

  fora(i, n) {
    cin >> aux1 >> aux2;
    if(programas[aux1] < aux2) {
      novos.insert(aux1);
      programas[aux1] = aux2;
    }
  }

  forita(it, novos)
  {
    cout << *it << " " << programas[*it] << endl;
  }

  return 0;
}
