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

int n;
long long memo[5050];
int v[5050];
string s;

long long dp(int i) {
	// Base
	if (i == n) return 1;
	if (v[i] == 0) return 0;
	if (i == n - 1) return 1;

	long long pdm = memo[i];
	if (pdm != -1) return pdm;

	pdm = dp(i + 1);
	if (v[i] * 10 + v[i + 1] <= 26) pdm += dp(i + 2);

	memo[i] = pdm;
	return pdm;
}

int main(int argc, char const *argv[]) {
	fastio;

	getline(cin, s);

	while (s[0] != '0') {
		n = s.size();

		fr(i, n) {
			v[i] = s[i] - '0';
			memo[i] = -1;
		}

		cout << dp(0) << endl;
    getline(cin, s);
	}

	return 0;
}
