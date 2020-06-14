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
const ll M = 1000000009;
// ===================================================== //

typedef vector<vector<ll> > matrix;

ll n;

matrix operator*(matrix &a, matrix &b) {
	int n = (int)a.size();
	int m = (int)b[0].size();
	int p = (int)a[0].size();

	matrix c(n, vl(m));

	fr(i, n) fr(j, m) {
		c[i][j] = 0;
		fr(k, p) {
			c[i][j] += (a[i][k] * b[k][j]) % M;
			c[i][j] %= M;
		}
	}

	return c;
}

matrix fastxp(matrix &base, ll exp) {
	if (exp == 0) {
		matrix c(base.size(), vl(base.size()));
		fr(i, n) c[i][i] = 1;
		return c;
	}
	if (exp == 1) return base;

	if (exp % 2 == 1) {
		matrix c = fastxp(base, exp - 1);
		return c * base;
	}
	matrix c = fastxp(base, exp / 2);
	return c * c;
}

int main(int argc, char const *argv[]) {
	fastio;

	matrix trib(3, vl(3));
	trib[0] = { 1, 1, 1 };
	trib[1] = { 1, 0, 0 };
	trib[2] = { 0, 1, 0 };
	matrix base(3, vl(1));
	base[0][0] = 2;
	base[1][0] = 1;
	base[2][0] = 0;

	cin >> n;
	while (n) {
		if (n <= 2)
			cout << base[3 - n][0] << endl;
		else {
			matrix tribk = fastxp(trib, n - 3);
			matrix ans = tribk * base;
			cout << ans[0][0] << endl;
		}
		cin >> n;
	}

	return 0;
}
