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
ll u, v, w;
vector<pair<ll, pll>> edges;

//Union Find
ll id[512], sz[512];
void makeSets() { forai (i, n) id[i] = i, sz[i] = 1; }
ll find(ll i) { return (id[i] == i) ? i : id[i] = find(id[i]); }
void join(ll i, ll j) {
  i = find(i); j = find(j);
  if (i == j) return;
  if (sz[i] > sz[j]) swap(i, j);
  id[i] = j; sz[j] += sz[i];
}

ll kruskal() {
  ll min = 0;
  makeSets();
  sortvector(edges);
  forita(it, edges) {
    if (find(it->s.f) != find(it->s.s)) {
      join(it->s.f, it->s.s);
      min += it->f;
    }
  }
  return min;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  fora(i, m) {
    get3(u, v, w);
    edges.pb(mk(w, mk(u, v)));
  }

  cout1e(kruskal());

  return 0;
}
