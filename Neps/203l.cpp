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
#define mk make_pair
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

ll n, m;
vector<ll> adj[1123];
ll comp[1123];
ll x, y;
ll ncomps;

void dfs(ll i) {
  forita (it, adj[i]) {
    if(comp[*it] == -1) {
      comp[*it] = comp[i];
      dfs(*it);
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);

  fora(i, n+1) comp[i] = -1;

  fora(i, m) {
    get2(x, y);
    adj[x].pb(y);
    adj[y].pb(x);
  }

  ncomps = 0;
  forai(i, n) {
    if (comp[i] == -1) {
      comp[i] = ncomps++;
      dfs(i);
    }
  }

  cout1e(ncomps);

  return 0;
}
