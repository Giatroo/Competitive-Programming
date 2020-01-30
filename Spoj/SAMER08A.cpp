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
#define INF LLONG_MAX

using namespace std;

ll n, m;
ll s, d;
ll u, v, p;
set<ll> lasts;
vector<pll> adj[512];
pll dist[512];

void dijkstraMin(ll S) {
  ll minPath = INF;
  set<pair<pll, ll>> pq;
  pair<pll, ll> aux;
  fora(i, n + 3) dist[i] = mk(INF, -1);
  pq.insert(mk(mk(0, S), -1));

  while (!pq.empty()) {
    aux = *pq.begin(); pq.erase(pq.begin());

    if (dist[aux.f.s].s == -1) {
      dist[aux.f.s].f = aux.f.f;
      dist[aux.f.s].s = aux.s;

      forita (it, adj[aux.f.s]) {
        if (dist[it->f].f > dist[aux.f.s].f + it->s) {
          pq.insert(mk(mk(dist[aux.f.s].f + it->s, it->f), aux.f.s));

          if (it->f == d) {
            if (dist[aux.f.s].f + it->s < minPath) {
              lasts.clear();
              lasts.insert(aux.f.s);
              minPath = dist[aux.f.s].f + it->s;
            } else if (dist[aux.f.s].f + it->s == minPath)
              lasts.insert(aux.f.s);
          }
        }
      }
    }
  }
}

void removeMinPaths() {
  ll cur, ant;
  // cout << "Recuperando caminhos" << endl;
  while (!lasts.empty()) {
    cur = *lasts.begin(); lasts.erase(lasts.begin());
    ant = d;
    while (cur != s) {
      // cout1(cur) << " ";

      forita (it, adj[cur]) {
        if (it->f == ant) {
          adj[cur].erase(it);
          break;
        }
      }

      ant = cur;
      cur = dist[cur].s;
    }

    forita (it, adj[cur]) {
      if (it->f == ant) {
        adj[cur].erase(it);
        break;
      }
    }
    // cout << endl;
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  while (n*m != 0) {
    get2(s, d);
    fora(i, m) {
      get3(u, v, p);
      adj[u].pb(mk(v, p));
    }

    dijkstraMin(s);
    removeMinPaths();
    dijkstraMin(s);
    if (dist[d].f == INF) cout1e(-1);
    else cout1e(dist[d].f);

    fora(i, n + 4) adj[i].clear();
    lasts.clear();
    get2(n, m);
  }

  return 0;
}
