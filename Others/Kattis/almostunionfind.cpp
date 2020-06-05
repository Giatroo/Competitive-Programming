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
int uf[2 * N], w[2 * N];
ll sum[2 * N];
int reali[N];
int curmax;
int n, m, p, q, o;

void build() {
	frr(i, n) {
		uf[i] = reali[i] = sum[i] = i;
		w[i] = 1;
	}
	curmax = n;
}

int find(int u) { return (uf[u] == u ? u : uf[u] = find(uf[u])); }

void join(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	if (w[u] < w[v]) swap(u, v);

	w[u] += w[v];
	sum[u] += sum[v];
	uf[v] = u;
}

void move(int u, int v) {
	int f = find(reali[u]);
	if (f == find(reali[v])) return;
	sum[f] -= u;
	w[f]--;

	curmax++;
	uf[curmax] = curmax;
	sum[curmax] = u;
	w[curmax] = 1;
	reali[curmax] = 0;
	reali[u] = curmax;
	join(curmax, reali[v]);
}

void info(int u) {
	u = find(u);
	cout << w[u] << ' ' << sum[u] << endl;
}

void show() {
	frr(i, curmax) {
		cout << debug(i) << debug(uf[i]) << debug(w[i]);
		cout << debug(sum[i]) << debug(reali[i]) << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	fastio;

	while (cin >> n >> m) {
		build();
		// show();

		fr(i, m) {
			cin >> o;
			switch (o) {
				case 1:
					cin >> p >> q;
					join(reali[p], reali[q]);
					// show();
          break;
				case 2:
					cin >> p >> q;
					move(p, q);
					// show();
					break;
				case 3:
					cin >> p;
					info(reali[p]);
					break;
			}
		}
	}

	return 0;
}
