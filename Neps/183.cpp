#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define cout1e(a) cout << (a) << endl
#define cout2e(a, b) cout << (a) << " " << (b) << endl
#define cout3e(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define cout4e(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define debug(x) cout << #x << " = " << x << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

const int N = 1123;
int n, m, u, v, p;
vector<pii> adj[N];
int s;
int d[N];

void dij(int sr) {
	set<pii> dj;
	frr (i, n) d[i] = INF;
	d[sr] = 0;
	dj.insert(mk(0, sr));	
	
	pii p;
	while (!dj.empty()) {
		p = *dj.begin(); dj.erase(dj.begin());
		
		forita (it, adj[p.s]) {
			if (d[p.s] + it->s < d[it->f]) {
				d[it->f] = d[p.s] + it->s;
				dj.insert(mk(d[it->f], it->f));
			}
		}
	}

}

int main(int argc, char const *argv[]) { fastio;

	cin >> n >> m;
	fr (i, m) {
		get3(u, v, p);
		adj[u].pb(mk(v, p));
		adj[v].pb(mk(u, p));
	}
	
	cin >> s;
	dij(s);

	// frr (i, n) printf("d[%d] = %d\n", i, d[i]);

	int l, h;
	l = INF; h = -INF;
	frr (i, n) {
		if (i == s) continue;
		h = max(h, d[i]);
		l = min(l, d[i]);
	}

	cout << h-l << endl;

  return 0;
}
