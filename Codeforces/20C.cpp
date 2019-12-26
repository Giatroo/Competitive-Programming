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
ll a, b, w;
vector<pll> adj[112345];
pll dist[112345];

void dijkstra(ll S) {
  set<pair<pll, ll>> pq;
  pair<pll, ll> aux;
  fora(i, n + 3) dist[i] = mk(INF, -1);
  pq.insert(mk(mk(0, S), -1));

  while (!pq.empty()) {
    aux = *pq.begin(); pq.erase(pq.begin());

    if (dist[aux.f.s].s == -1) {
      dist[aux.f.s].f = aux.f.f;
      dist[aux.f.s].s = aux.s;

      forita (it, adj[aux.f.s])
        if (dist[it->f].f > aux.f.f + it->s)
          pq.insert(mk(mk(aux.f.f + it->s, it->f), aux.f.s));
    }
  }
}

void getPath() {
  stack<ll> path;
  ll cur = n;

  if (dist[cur].f == INF) {
    cout1e(-1);
    return;
  }

  while (cur != 1) {
    path.push(cur);
    cur = dist[cur].s;
  }

  cout1(1) << " ";
  while (!path.empty()) {
    cout1(path.top()) << " ";
    path.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  fora(i, m) {
    get3(a, b, w);
    if (a == b) continue;
    adj[a].pb(mk(b, w));
    adj[b].pb(mk(a, w));
  }

  dijkstra(1);
  getPath();


  return 0;
}
