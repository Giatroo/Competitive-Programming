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
ll dp[11234];

int main(int argc, char const *argv[]) {
	fastio;
	dp[0] = dp[1] = 1;
	dp[2] = 5;
  cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = 1 * dp[i - 1];
		dp[i] %= M;
		dp[i] += 4 * dp[i - 2];
		dp[i] %= M;
		dp[i] += 2 * dp[i - 3];
		dp[i] %= M;
	}
  cout << dp[n] << endl;

	return 0;
}
