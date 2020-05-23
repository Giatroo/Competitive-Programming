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
const ll M = 998244353;
// ===================================================== //

const int N = 1123;
ll n, k;
ll arr[N];
ll dp[N][N];
map<ll, ll> freq;
ll v[N];

ll f(ll cur, ll park) {
	if (park == k) return 1;
	if (cur == freq.size()) return 0;

	if (dp[cur][park] != -1) return dp[cur][park];

	ll pegar = f(cur + 1, park + 1);
	ll npegar = f(cur + 1, park);

	return dp[cur][park] = ((v[cur] * pegar + npegar) % M);
}

int main(int argc, char const *argv[]) {
	fastio;
	cin >> n >> k;
	fr(i, n) {
		cin >> arr[i];
		freq[arr[i]]++;
	}
	fr(i, n + 2) fr(j, n + 2) dp[i][j] = -1;
	ll i = 0;
	forita(it, freq) {
		v[i++] = it->second;
		// cout1e(v[i-1]);
	}

	cout1e(f(0, 0));

	return 0;
}
