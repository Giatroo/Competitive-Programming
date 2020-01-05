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

set<int> a, b, ac, bc;
int na, nb;
int aux;

int main(int argc, char const *argv[]) {
  //Input
  cin >> na >> nb;

  fora(i, na)
  {
    cin >> aux;
    a.insert(aux);
    ac.insert(aux);
  }

  fora(i, nb)
  {
    cin >> aux;
    b.insert(aux);
    bc.insert(aux);
  }

  //Processing
  for(set<int>::iterator it = a.begin(); it != a.end(); it++)
    bc.insert(*it);

  for(set<int>::iterator it = b.begin(); it != b.end(); it++)
    ac.insert(*it);

  cout << min( ac.size() - a.size() , bc.size() - b.size() ) << endl;

  return 0;
}
