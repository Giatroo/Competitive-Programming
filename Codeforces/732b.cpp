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

const int N = 512;
int n, k;
int a[N], b[N];
int tot;

int main(int argc, char const *argv[]) {
	fastio;
	cin >> n >> k;
	fr(i, n) cin >> a[i];

	b[0] = a[0];
	tot = 0;
	frr(i, n - 1) {
		b[i] = k - b[i - 1];
    if (b[i] < a[i]) b[i] = a[i];
		tot += b[i] - a[i];
	}
	if (tot >= 0) {
		cout << tot << endl;
		fr(i, n) cout << b[i] << " ";
		cout << endl;
	} else {
     cout << 0 << endl;
     fr(i, n) cout << a[i] << ' ';
     cout << endl;
  }

	return 0;
}
