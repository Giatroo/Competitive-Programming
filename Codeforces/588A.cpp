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

ll n, c;
ll i, j;
pair<ll, ll> dias[112345]; //quilos , custo

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fora(i, n) { cin >> dias[i].f >> dias[i].s; }
  c = 0;

  for(i = 0; i < n;) {
    c += dias[i].f * dias[i].s;

    //Olho para frente
    j = i + 1;
    while (dias[i].s < dias[j].s) {
      c += dias[j].f * dias[i].s;
      j++;
    }
    i = j;
  }

  cout << c << endl;

  return 0;
}
