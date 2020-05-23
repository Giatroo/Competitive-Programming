#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for (auto it = c.begin(); it != c.end(); it++)

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

int n, m;
char c[512][512];

void bfs(int i, int j) {
	queue<pii> q;
	q.push(mk(i, j));
	pii cur;

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.f + 1 < n && c[cur.f + 1][cur.s] == '#') {
			if (cur.s + 1 < m && c[cur.f][cur.s + 1] != 'o') {
				q.push(mk(cur.f, cur.s + 1));
				c[cur.f][cur.s + 1] = 'o';
			}
			if (cur.s - 1 >= 0 && c[cur.f][cur.s - 1] != 'o') {
				q.push(mk(cur.f, cur.s - 1));
				c[cur.f][cur.s - 1] = 'o';
			}
		} else if (cur.f + 1 < n && c[cur.f + 1][cur.s] == '.') {
			q.push(mk(cur.f + 1, cur.s));
			c[cur.f + 1][cur.s] = 'o';
		}
	}
}

int main(int argc, char const *argv[]) {
	fastio;
	int inii, inij;
	cin >> n >> m;
	fr(i, n) fr(j, m) {
		cin >> c[i][j];
		if (c[i][j] == 'o') {
			inii = i;
			inij = j;
		}
	}

	bfs(inii, inij);
	fr(i, n) {
		fr(j, m) cout << c[i][j];
		cout << endl;
	}

	return 0;
}
