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

const int N = 11234;
int n, a, b;
int p, q, w;
vector<pii> adj[N];
int d[N];

int dij() {
	set<pii> s;
	frr (i, n) d[i] = INF;
	d[a] = 0;
	s.insert(mk(0, a));
	
	pii cur;
	while (!s.empty()) {
		cur = *s.begin(); s.erase(s.begin());
		
		forita (it, adj[cur.s]) {
			if (d[cur.s] + it->s < d[it->f]) {
				d[it->f] = d[cur.s] + it->s;
				s.insert(mk(d[it->f], it->f));
			}
			if (it->f == b) return d[b];
		}		

	}
	return d[b];
}

int main(int argc, char const *argv[]) { fastio;

	get3(n, a, b);
	fr (i, n-1) {
		get3(p, q, w);
		adj[p].pb(mk(q, w)); adj[q].pb(mk(p, w));
	}
	cout1e(dij()); 

  return 0;
}
