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

int t, n, m, x, y;
char s[112][1123];
bool onebetter;
int tot;

int main(int argc, char const *argv[]) {
	fastio;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		fr(i, n) fr(j, m) cin >> s[i][j];

		onebetter = (2 * x <= y);
		tot = 0;

		fr(i, n) {
			for (int j = 0; j < m;) {
				if (s[i][j] == '*') {
					j++;
					continue;
				}
				if (j + 1 == m) {
					j++;
					tot += x;
					continue;
				}

				if (s[i][j + 1] == '.') {
					if (onebetter) {
						tot += 2 * x;
						j += 2;
					} else {
						tot += y;
						j+= 2;
					}

				} else {
					tot += x;
					j++;
				}
			}
		}
		cout << tot << endl;
	}

	return 0;
}
