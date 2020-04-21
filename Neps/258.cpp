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
int n;
int x, y;
int grid[N][N];
int tot;
int vx[] = { 0, 1, 0, -1 };
int vy[] = { 1, 0, -1, 0 };

int bfs() {
	stack<pii> q;
	pii s = mk(x, y);
	q.push(s);
	tot = 0;

	while (!q.empty()) {
		s = q.top(); q.pop();

		if (grid[s.f][s.s] == -1) continue;

		for (int k = 0; k <= 3; k++) {
			if (s.f+vx[k] < 0 || s.f+vx[k] >= n || s.s+vy[k] < 0 || s.s+vy[k] >= n)
				continue;
			if (grid[s.f+vx[k]][s.s+vy[k]] == -1) continue;
			
			if (grid[s.f+vx[k]][s.s+vy[k]] >= grid[s.f][s.s]) { 
				q.push(mk(s.f+vx[k],s.s+vy[k]));
			}
		}

		grid[s.f][s.s] = -1; tot++;	
	}
	return tot;	
}

int main(int argc, char const *argv[]) { fastio;
	cin >> n >> x >> y;
	x--; y--;
	fr (i, n) fr(j, n) cin >> grid[i][j];
	cout1e(bfs());

  return 0;
}
