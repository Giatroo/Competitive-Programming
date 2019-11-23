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

pair<ll, ll> pont;
ll n, m;
ll aux;
char d;
bool s;

lld dist()
{
  return sqrt(pont.f*pont.f + pont.s*pont.s);
}

int main(int argc, char const *argv[]) {
  pont.f = pont.s = 0;
  cin >> n >> m;
  s = false;

  fora(i, n)
  {
    cin >> d >> aux;
    if(d == 'N') pont.s += aux;
    else if(d == 'S') pont.s -= aux;
    else if(d == 'L') pont.f += aux;
    else if(d == 'O') pont.f -= aux;

    if(dist() > m) {
      s = true; break;
    }
  }

  if(s) cout << 1 << endl;
  else cout << 0 << endl;

  return 0;
}
