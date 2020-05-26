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

#define y1 dhua

const int N = 1123;
int n, m, q;
int x1, x2, y1, y2;
vector<tuple<int, int, int, int>> querrys;
stack<bool> art[N][N];

int uf[N * N], w[N * N];
stack<int> ans;

int vx[4] = { -1, 1, 0, 0 };
int vy[4] = { 0, 0, 1, -1 };

void build() {
	for (int i = 0; i < n * m; i++) {
		uf[i] = -1;
		w[i] = 1;
	}
}

int find(int u) { return (uf[u] == u ? u : uf[u] = find(uf[u])); }

void join(int u, int v) {
	u = find(u);
	v = find(v);
	if (w[u] < w[v]) swap(u, v);
	w[u] += w[v];
	uf[v] = u;
}

bool inside(pii p) { return 0 <= p.f && p.f < n && 0 <= p.s && p.s < m; }

void dfs(pii s, int comp) {
	stack<pii> st;
	st.push(s);
	uf[s.f * m + s.s] = comp;

	pii cur;
	while (!st.empty()) {
		s = st.top();
		st.pop();
		fr(k, 4) {
			cur = mk(s.f + vx[k], s.s + vy[k]);
			if (inside(cur) && art[cur.f][cur.s].top() == false && uf[cur.f * m + cur.s] == -1) {
				uf[cur.f * m + cur.s] = comp;
				st.push(cur);
			}
		}
	}
}

void alldfs() {
	int comp = 0;
	fr(i, n) fr(j, m) {
		if (art[i][j].top() == false && uf[i * m + j] == -1) {
			comp++;
			dfs(mk(i, j), i * m + j);
		}
	}

	// fr(i, n) {
		// fr(j, m) cout << uf[i * m + j] << " ";
		// cout << endl;
	// }
	// cout << endl << comp << endl;
	ans.push(comp);

	pii cur;
	for (int k = querrys.size() - 1; k >= 0; k--) {
		x1 = get<0>(querrys[k]);
		x2 = get<1>(querrys[k]);
		y1 = get<2>(querrys[k]);
		y2 = get<3>(querrys[k]);

		// cout << get<0>(querrys[k]) << get<1>(querrys[k]) << get<2>(querrys[k])
				 // << get<3>(querrys[k]);
		// cout << endl;
		// cout << debug(x1) << debug(x2) << debug(y1) << debug(y2) << endl;

		pii l, r, u, d;
		bool allblack;
		if (x1 == x2) {
			for (; y1 <= y2; y1++) {
				art[x1][y1].pop();
				if (art[x1][y1].top() == true) continue;

				allblack = true;
				fr(kk, 4) {
					l = mk(x1 + vx[kk], y1 + vy[kk]);

					if (inside(l) && art[l.f][l.s].top() == false) {
						allblack = false;
						if (uf[x1 * m + y1] == -1) {
							uf[x1 * m + y1] = uf[l.f * m + l.s];
							// cout << debug(uf[x1 * m + y1]) << endl;
						} else {
							// cout << debug(uf[x1 * m + y1]) << debug(uf[l.f * m + l.s]) << endl;
							if (find(x1 * m + y1) != find(l.f * m + l.s)) {
								comp--;
								join(x1 * m + y1, l.f * m + l.s);
								// cout << "Juntando " << x1 << " " << y1 << " com " << l.f << " "
										 // << l.s << endl;
							}
						}
					}
				}

				if (allblack) {
					// cout << "allblack" << endl;
					uf[x1 * m + y1] = x1 * m + y1;
					comp++;
				}
			}

		} else {
			for (; x1 <= x2; x1++) {
				art[x1][y1].pop();
				if (art[x1][y1].top() == true) continue;

				allblack = true;
				fr(kk, 4) {
					l = mk(x1 + vx[kk], y1 + vy[kk]);

					if (inside(l) && art[l.f][l.s].top() == false) {
						allblack = false;
						if (uf[x1 * m + y1] == -1) {
							uf[x1 * m + y1] = uf[l.f * m + l.s];
							// cout << debug(uf[x1 * m + y1]) << endl;
            }
						else {
							// cout << debug(uf[x1 * m + y1]) << debug(uf[l.f * m + l.s]) << endl;
							if (find(x1 * m + y1) != find(l.f * m + l.s)) {
								comp--;
								join(x1 * m + y1, l.f * m + l.s);
								// cout << "Juntando " << x1 << " " << y1 << " com " << l.f << " "
										 // << l.s << endl;
							}
						}
					}
				}

				if (allblack) {
					// cout << "allblack" << endl;
					uf[x1 * m + y1] = x1 * m + y1;
					comp++;
				}
			}
		}

		// fr(i, n) {
			// fr(j, m) cout << uf[i * m + j] << " ";
			// cout << endl;
		// }
		// cout << comp << endl << endl;
		ans.push(comp);
	}

  ans.pop();
	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
}

int main(int argc, char const *argv[]) {
	fastio;
	cin >> m >> n >> q;
	fr(i, n) fr(j, m) art[i][j].push(false);

	fr(k, q) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		x2--;
		y1--;
		y2--;
		swap(x1, y1);
		swap(x2, y2);
		querrys.push_back(make_tuple(x1, x2, y1, y2));
		for (; x1 != x2 || y1 != y2;) {
			art[x1][y1].push(true);
			if (x1 != x2) x1++;
			if (y1 != y2) y1++;
		}
		art[x2][y2].push(true);
	}

	// fr(i, n) {
		// fr(j, m) cout << art[i][j].top();
		// cout << endl;
	// }
	// cout << endl;

	// fr(i, querrys.size()) {
		// cout << get<0>(querrys[i]) << get<1>(querrys[i]) << get<2>(querrys[i])
				 // << get<3>(querrys[i]);
		// cout << endl;
	// }

	build();
	alldfs();

	return 0;
}
