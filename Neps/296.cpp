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
#define INF INT_MAX

using namespace std;

ll n, m, c, k;
ll u, v, p;
vector<pll> adj[312];
ll t;
ll dist[312];

void dijkstra(ll S) {
  set<pll> pq;
  pll aux;
  fora(i, n) dist[i] = INF;
  pq.insert(mk(0, S));

  while (!pq.empty()) {
    aux = *pq.begin(); pq.erase(pq.begin());

    if (dist[aux.s] == INF) {
      // cout << "Olhando " << aux.s << endl;
      dist[aux.s] = aux.f;

      forita(it, adj[aux.s]) {
        // cout << it->f << " é vizinho do " << aux.s << endl;
        if (dist[it->f] > dist[aux.s] + it->s)
          pq.insert(mk(dist[aux.s] + it->s, it->f));
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  get2(c, k);
  while (n*m != 0 && c*k != 0) {
    fora(i, m) {
      get3(u, v, p);
      if (u < c && v < c) { // os dois estão no caminho
        if (abs(u-v) != 1) continue;
        if (u > v) { ll aux = u; u = v; v = aux; }
        // u agora é o menor
        adj[u].pb(mk(v, p)); //u para v, mas não v para u
      } else if (u < c || v < c) { //um apenas está no caminho
        if (u > v) { ll aux = u; u = v; v = aux; }
        // u é o cara dentro do caminho
        adj[v].pb(mk(u, p)); //v para u, mas não u para v
      } else { //os dois não estão no caminho
        adj[u].pb(mk(v, p)); //u para v
        adj[v].pb(mk(u, p)); //v para u
      }
    }

    dijkstra(k);
    cout1e(dist[c-1]);

    fora(i, n + 2) adj[i].clear();
    get2(n, m);
    get2(c, k);
  }


  return 0;
}
