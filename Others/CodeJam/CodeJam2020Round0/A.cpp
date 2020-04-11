#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

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

int t, n;
int m[112][112];
int c;
int trace, numc, numr;
set<int> s;

int main(int argc, char const *argv[]) { fastio;

	cin >> t;
	c = 0;
	while (t--) {
		cin >> n;
		trace = numc = numr = 0;

		fr (i, n) fr (j, n) cin >> m[i][j];
		fr (i, n) trace += m[i][i];


		fr (i, n) {
			s.clear();
			fr (j, n) {
				if (s.count(m[i][j])) { numr++; break; }
				s.insert(m[i][j]);
			}
		}

		fr (i, n) {
			s.clear();
			fr (j, n) {
				if (s.count(m[j][i])) { numc++; break; }
				s.insert(m[j][i]);
			}
		}

		cout << "Case #" << ++c << ": ";
		cout3e(trace, numr, numc);

	}

  return 0;
}
