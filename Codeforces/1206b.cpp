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
int a;
ll ans;
int nm, np, nz;

int main(int argc, char const *argv[]) {
	fastio;
	ans = nm = np = 0;
	cin >> n;

	fr(i, n - 1) {
		cin >> a;
		if (a == -1) nm++;
		else if (a == 1) np++;
		else if (a == 0) nz++;
		else if (a < -1) { ans += abs(a + 1); nm++; }
    else if (a > 1) { ans += abs(a - 1); np++; }
	}

	cin >> a;
	if (nz > 0) {
		if (a == -1) nm++;
		else if (a == 1) np++;
		else if (a == 0) nz++;
		else if (a < -1) { ans += abs(a + 1); nm++; }
    else if (a > 1) { ans += abs(a - 1); np++; }

		ans += nz;
	} else {
		if (nm % 2 == 0) ans += abs(a - 1);
		else ans += abs(a + 1);
	}
	cout << ans << endl;

	return 0;
}
