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

const int N = 112;
int n, m;
vector<pii> adj[N];
int a, b, c;
int dist[N];

int dij(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> p;
	frr (i, n) dist[i] = INF;
	dist[s] = 0;
	p.push(mk(0, s));
	
	pii pa;
	while (!p.empty()) {
		pa = p.top(); p.pop();
		
		if (pa.s == n) break;

		forita (it, adj[pa.s]) {
			if (dist[it->f] > dist[pa.s] + it->s) { 
				dist[it->f] = dist[pa.s] + it->s;
				p.push(mk(dist[it->f], it->f));
			}
		}
	}
	return dist[n];
}

int main(int argc, char const *argv[]) { fastio;

	cin >> n >> m;
	fr (i, m) {
		get3(a, b, c);
		adj[a].pb(mk(b, c));
		adj[b].pb(mk(a, c));
	}

	cout << dij(1) << endl;

  return 0;
}














