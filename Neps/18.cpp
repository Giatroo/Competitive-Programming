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

vector<int> adj[512];
int w[512];
int v[512];
int t[512];
bool vis[512];
int n, m, o;
int a, b;
char c;

int dfs(int s) {
	int mini = INF;
	stack<int> st;

	frr (i, n) vis[i] = false;
	vis[s] = true;

	forita (it, adj[s]) {
		st.push(*it);
	}

	while (!st.empty()) {
		s = st.top(); st.pop();
		vis[s] = true;
		mini = min(mini, t[v[s]]);
		forita (it, adj[s])
			if (!vis[*it]) st.push(*it);
	}
	return mini;
}

int main() { fastio;
	get3(n, m, o);

	frr (i, n) get1(t[i]);
	frr (i, n) { w[i] = v[i] = i; }
	frr (i, m) {
		get2(a, b);
		adj[b].pb(a);
	}
	fr (i, o) {
		get1(c);
		if (c == 'P') {
			get1(a);
			b = dfs(w[a]);
			if (b == INF) cout1e("*");
			else cout1e(b);
		} else {
			get2(a, b);
			swap(v[w[a]], v[w[b]]);
			swap(w[a], w[b]);
		}
	}
	

	return 0;
}
