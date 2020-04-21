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

const int N = 112345;
int n, m;
vector<int> adj[N];
int d[N];
int gen[N];
int go[N];
int lastGen;
int u;

void bfs() {
	int s = 0;
	queue<int> q;
	q.push(s);
	fr (i, n+1) d[i] = -1;
	fr (i, n+1) go[i] = gen[i] = 0;
	d[0] = 0;
	gen[d[0]]++;
	lastGen = 0;
	
	while (!q.empty()) {
		s = q.front(); q.pop();
		forita (it, adj[s]) {
			if (d[*it] == -1) {
				d[*it] = d[s] + 1;
				gen[d[*it]]++;
				lastGen= max(d[*it], lastGen);
				q.push(*it);
			}
		}
	}
}


int main(int argc, char const *argv[]) { 
	cin >> n >> m;
	frr (i, n) {
		cin >> u;
		adj[u].pb(i); 
		adj[i].pb(u);
	}	
	bfs();
	frr (i, m) {
		cin >> u;
		go[d[u]]++;
	}

	frr (i, lastGen) 
		printf("%.2lf ", ((double)go[i])/gen[i]*100); 
	printf("\n");

  return 0;
}
