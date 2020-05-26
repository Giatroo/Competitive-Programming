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

#define debug(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

const int N = 112;
ll n, a, d;
char adj[N][N];
ll uf[N], w[N];

ll find(ll u) { return (uf[u] == u ? u : uf[u] = find(uf[u])); }

void join(ll u, ll v) {
	u = find(u);
	v = find(v);
	if (w[u] < w[v]) swap(u, v);
	w[u] += w[v];
	uf[v] = u;
}

void bfs(ll s, ll comp) {
	for (ll i = 0; i < n; i++) {
		if (adj[s][i] == '1' && uf[i] != comp) {
			uf[i] = comp;
			adj[s][i] = adj[i][s] = '2';
			bfs(i, comp);
		}
	}
}

void allbfs() {
	ll tot = 0;
	fr(i, n) {
		uf[i] = -1;
		w[i] = 1;
	}

	fr(i, n) {
		if (uf[i] == -1) {
			uf[i] = i;
			bfs(i, i);
		}
	}

	fr(i, n) {
		if (find(0) != find(i)) {
			join(0, i);
			adj[0][i] = adj[i][0] = 'a';
			tot += a;
		}
	}

	fr(i, n) fr(j, n) {
		if (adj[i][j] == '2') adj[i][j] = adj[j][i] = '0';

		if (adj[i][j] == '1') {
			adj[i][j] = adj[j][i] = 'd';
			tot += d;
		}
	}

	cout << tot << endl;
}

int main(int argc, char const *argv[]) {
	fastio;
	cin >> n;
	cin >> d >> a;

	fr(i, n) fr(j, n) cin >> adj[i][j];

	allbfs();

	fr(i, n) {
		fr(j, n) cout << adj[i][j];
		cout << endl;
	}

	return 0;
}
