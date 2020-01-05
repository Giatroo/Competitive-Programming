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
ll x, y, w;
vector<pair<ll, pll>> edges; //cost, pair(v1, v2)
ll id[112], sz[112]; //union-find (1-indexed)
vector<pll> solution;
ll num;

void MakeSets() {
  forai(i, n)
    id[i] = i, sz[i] = 1;
}

ll Find(ll i) {
  if (id[i] == i) return i;
  return id[i] = Find(id[i]);
}

void Join(ll i, ll j) {
  i = Find(i);
  j = Find(j);
  if (sz[i] > sz[j]) { ll aux = i; i = j; j = aux; }
  id[i] = j;
  sz[j] += sz[i];
}

void Kruskal() {
  MakeSets();
  solution.clear();
  sortvector(edges); // sorting by weight
  forita (it, edges) {
    if (Find(it->s.f) == Find(it->s.s)) continue;
    solution.pb(mk(it->s.f, it->s.s));
    Join(it->s.f, it->s.s);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  num = 1;
  while (n * m != 0) {
    fora(i, m) {
      get3(x, y, w);
      if (x > y) { ll aux = x; x = y; y = aux; }
      edges.pb(mk(w, mk(x, y))); // (cost, lower, higher)
    }

    Kruskal();
    cout2e("Teste", num++);
    forita(it, solution)
      cout2e(it->f, it->s);
    cout << endl;

    edges.clear();
    get2(n, m);
  }

  return 0;
}
