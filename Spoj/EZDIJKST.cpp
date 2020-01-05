#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
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

ll t;
ll v, k;
ll a, b, c;
ll v1, v2;
vector<pll> adj[11234];
ll dist[11234];

void dijkstra(ll S) {
  set<pll> f;
  pll aux;
  forai(i, v) dist[i] = INT_MAX;
  f.insert(mk(0, S));

  while (!f.empty()) {
    aux = *f.begin();
    f.erase(f.begin());
    if (dist[aux.s] != INT_MAX) continue;
    // cout << "Olhando " << aux.s << endl;
    dist[aux.s] = aux.f;

    forita (it, adj[aux.s]) {
      // if (dist[it->f] != INT_MAX) continue;
      if (aux.f + it->s < dist[it->f])
        f.insert(mk(aux.f + it->s, it->f));
      }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  fora(i, t) {
    get2(v, k);
    fora(j, k) {
      get3(a, b, c);
      adj[a].pb(mk(b, c));
    }
    get2(v1, v2);
    dijkstra(v1);
    if (dist[v2] == INT_MAX) cout << "NO" << endl;
    else cout << dist[v2] << endl;
    // forai(i, v) cout << dist[i] << " ";
    // cout << endl;

    fora(j, v + 2) adj[j].clear();
  }


  return 0;
}
