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

int n, d;
string lily;
int cur;
int njumps;
int i;

int main(int argc, char const *argv[]) {
	fastio;
	cin >> n >> d;
  cin >> lily;
	cur = 0;
	njumps = 0;

	while (cur != n-1) {
		if (cur + d >= n-1) {
			njumps++;
			break;
		}
		for (i = d; i > 0; i--) {
      if (lily[cur+i] == '1') {
        cur = cur+i;
        njumps++;
        break;
      }
    }
    if (i == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

	cout << njumps << endl;

	return 0;
}
