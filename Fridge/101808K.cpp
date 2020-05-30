#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for (auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define debug(x) #x << " = " << x << " "

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

const int N = 112345;
const int L = 23;

vector<pii> adj[N];
pii cycle_edge;
int cycle_cost;
int anc[N][L];
int depth[N];
int d[N];
int parent[N];
int t, n, q;
int u, v, w;

void dfs(int s) {
	stack<int> q;
	q.push(s);
	fr(i, n + 2) parent[i] = -1;
	parent[s] = N;

	while (!q.empty()) {
		s = q.top();
		q.pop();
    cout << debug(s) << endl;

		for (pii i : adj[s]) {
			if (parent[i.f] == -1) {
				parent[i.f] = s;
				q.push(i.f);
			} else if (parent[s] != i.f) {
        cout << "Achamos o ciclo" << endl;
        cout << debug(i.f) << debug(s) << endl;
				cycle_edge = mk(i.f, s);
				cycle_cost = i.s;
				return;
			}
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	fr(i, n + 2) depth[i] = -1;
	depth[s] = 0;
	d[s] = 0;

	bool cicloEmMim;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		cicloEmMim = (cycle_edge.f == s || cycle_edge.s == s);
		for (pii i : adj[s]) {
			if (cicloEmMim && (cycle_edge.f == i.f || cycle_edge.s == i.f)) continue;
			if (depth[i.f] != -1) {
				anc[s][0] = i.f;
				continue;
			}
			depth[i.f] = depth[s] + 1;
			d[i.f] = d[s] + i.s;
			q.push(i.f);
		}
	}
}

void build_anc() {
	fr(i, n+3) fr(j, L) anc[i][j] = 0;
	dfs(1);
	bfs(1);
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++) anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int lca(int x, int y) {
  // cout << debug(depth[x]) << debug(depth[y]) << endl;
	if (depth[x] < depth[y]) swap(x, y);

	for (int i = L - 1; i >= 0; i--)
		if (depth[x] - (1 << i) >= depth[y]) x = anc[x][i];

  // cout << debug(x) << debug(y) << endl;
	if (x == y) return x;

	for (int i = L - 1; i >= 0; i--) {
		if (anc[x][i] != 0 && anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}

  // cout << debug(x) << endl;
	return anc[x][0];
}

int lfs;

int dist(int x, int y) {
	int l, lxf, lxs, lyf, lys;
	l = lca(x, y);
	int dl = d[x] + d[y] - 2 * d[l];
	lxf = lca(x, cycle_edge.f);
	lxs = lca(x, cycle_edge.s);
	lyf = lca(y, cycle_edge.f);
	lys = lca(y, cycle_edge.s);
	int dxf, dxs, dyf, dys;
	dxf = d[x] + d[cycle_edge.f] - 2 * d[lxf];
	dys = d[y] + d[cycle_edge.s] - 2 * d[lys];
	dxs = d[x] + d[cycle_edge.s] - 2 * d[lxs];
	dyf = d[y] + d[cycle_edge.f] - 2 * d[lyf];
  // cout << debug(x) << debug(y) << endl;
  // cout << debug(d[x]) << debug(d[y]) << debug(l) << debug(d[l]) << debug(dl) << endl;
  // cout << debug(d[cycle_edge.f]) << debug(d[cycle_edge.s]) << endl;
  // cout << debug(dxf) << debug(dxs) << debug(dyf) << debug(dys) << endl;
  // cout << debug(lxf) << debug(lxs) << debug(lyf) << debug(lys) << endl;

	int d1 = dxf + cycle_cost + dys;
	int d2 = dxs + cycle_cost + dyf;
	return min(d[x] + d[y] - 2 * d[l], min(d1, d2));
}

int main(int argc, char const *argv[]) {
	fastio;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		fr(i, n) {
			cin >> u >> v >> w;
			adj[u].pb(mk(v, w));
			adj[v].pb(mk(u, w));
		}
		build_anc();

		// cout << debug(cycle_edge.f) << debug(cycle_edge.s) << endl;
		lfs = lca(cycle_edge.f, cycle_edge.s);

		// for (int i = 1; i <= n; i++) {
			// cout << "Vértice " << i << " : ";
			// for (int j = 0; j <= 3; j++) cout << anc[i][j] << " ";
			// cout << endl;
		// }

    cout << debug(lca(10, 8)) << endl;

		fr(i, q) {
			cin >> u >> v;
      cout << dist(u, v) << endl;
      // cout << endl;
		}
		fr(i, n + 2) adj[i].clear();
    cout << endl; // apagar dps
	}

	return 0;
}
