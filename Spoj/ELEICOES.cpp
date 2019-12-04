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

ll n;
map<ll, ll> cands;
ll aux;
map<ll, ll>::iterator maxi;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fora(i, n) {
    cin >> aux;
    if (cands.find(aux) != cands.end()) {
      cands[aux]++;
    } else cands[aux] = 1;
  }

  maxi = cands.begin();
  forita(it, cands) {
    if (it->s > maxi->s) maxi = it;
  }

  printf("%lld\n", maxi->f);

  return 0;
}
