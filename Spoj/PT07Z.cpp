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

ll n;
ll a, b;
ll d1, d2;
vector<ll> adj[11234];
ll dist[11234];
set<ll> nodos;

ll bfs(ll v) {
  queue<ll> q;
  ll maxnode = v;
  forita(it, nodos) dist[*it] = -1;
  dist[v] = 0;
  q.push(v);

  while (!q.empty()) {
    v = q.front(); q.pop();

    forita(it, adj[v]) {
      if (dist[*it] == -1) {
        dist[*it] = dist[v] + 1;
        maxnode = *it;
        q.push(*it);
      }
    }
  }
  return maxnode;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  forai(i, n-1) {
    get2(a, b);
    nodos.insert(a);
    nodos.insert(b);
    adj[a].pb(b);
    adj[b].pb(a);
  }

  ll root = *nodos.begin();
  root = bfs(root);
  root = bfs(root);
  cout << dist[root] << endl;


  return 0;
}
