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
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

typedef tuple<ll, char, ll> peca;

peca pecas[112345];
ll i, n;

ll bs(ll l, ll r, ll x)
{
  ll m;
  while (l <= r) {
    m = (l + r) / 2;
    if (get<0>(pecas[m]) == x) return m;
    else if (get<0>(pecas[m]) < x) l = m + 1;
    else r = m - 1;
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fora(i, n)
    cin >> get<0>(pecas[i]) >> get<1>(pecas[i]) >> get<2>(pecas[i]);

  sort(pecas, pecas+n);

   i = 0;
   while (get<2>(pecas[i]) != 1){
     cout << get<1>(pecas[i]);
     i = bs(0, n-1, get<2>(pecas[i]));
  }
  cout << get<1>(pecas[i]) << endl;

  return 0;
}
