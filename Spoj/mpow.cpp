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

typedef vector<vector<ll> > matrix;
int t, m, n;

matrix operator*(matrix &a, matrix &b) {
	int n = (int)a.size();
	int m = (int)b[0].size();
	int p = (int)a[0].size();
	matrix c(n, vector<ll>(m));

	fr(i, n) fr(j, m) {
		c[i][j] = 0;
		fr(k, p) {
			c[i][j] += (a[i][k] * b[k][j]) % M;
			c[i][j] %= M;
		}
	}

	return c;
}

matrix fastxp(matrix &b, int exp) {
	if (exp == 0) {
		matrix c(b.size(), vector<ll>(b.size()));
		fr(i, b.size()) fr(j, b.size()) c[i][j] = (i == j);
		return c;
	}
	if (exp == 1) return b;
	if (exp % 2 == 1) {
    matrix c = fastxp(b, exp-1);
		return c*b;
  }
	else {
    matrix c = fastxp(b, exp/2);
		return c*c;
  }
}

int main(int argc, char const *argv[]) {
	fastio;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		matrix mat(m, vector<ll>(m));
		fr(i, m) fr(j, m) cin >> mat[i][j];

		mat = fastxp(mat, n);

		fr(i, m) {
			fr(j, m) cout << mat[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}
