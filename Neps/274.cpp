#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

vector<ll> myhash, fila;
ll N, M;
ll aux;

int main(int argc, char const *argv[]) {
  myhash.resize(112345);
  cin >> N;
  fora(i, N)
  {
    cin >> aux;
    fila.push_back(aux);
    myhash[aux] = fila.size() - 1;
  }

  cin >> M;
  fora(i, M)
  {
    cin >> aux;
    fila[myhash[aux]] = 0;
  }

  fora(i, N-1)
  {
    if(fila[i])
      cout << fila[i] << " ";
  }
  if(fila[N-1])
    cout << fila[N-1] << endl;
  else
    cout << endl;

  return 0;
}
