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
vector<ll> v;
vector<ll> vo;
ll tot;

int main(int argc, char const *argv[]) {
  cin >> n;
  v.resize(n);
  vo.resize(n);
  fora(i, n) { cin >> v[i]; vo[i] = v[i]; }
  sortvector(vo);

  tot = 0;
  fora(i, n) tot += abs(v[i] - (i + 1));

  cout << tot << endl;



  return 0;
}
