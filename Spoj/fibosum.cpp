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

typedef vector<vl> matrix;
ll n, m;
int t;

matrix operator*(matrix &a, matrix &b) {
	int n = a.size();
	int m = b[0].size();
	int p = a[0].size();

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

matrix fastxp(matrix base, int exp) {
	if (exp == 0) {
		matrix c(base.size(), vl(base.size()));
		fr(i, base.size()) c[i][i] = 1;
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

ll fibo(ll n) {
	if (n == 0 || n == 1) return n;
	matrix mat(2, vl(2));
	matrix base(2, vl(1));

	mat[0] = { 1, 1 };
	mat[1] = { 1, 0 };

	base[0][0] = 1;
	base[0][1] = 0;

	mat = fastxp(mat, n - 1);
	matrix ans = mat * base;
	return ans[0][0];
}

int main(int argc, char const *argv[]) {
	fastio;

	cin >> t;
  ll ans;
	while (t--) {
		cin >> n >> m;
		n--;
    // cout << debug(fibo(m+2)) << debug(fibo(n+2)) << endl;
    ans = (fibo(m + 2) - 1) - (fibo(n + 2) - 1);
    if (ans < 0) ans += M;
		cout << ans << endl;
	}

	return 0;
}
