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
const double EPS = 0.000000001;
// ===================================================== //

int a, b, c, d;
int n;
vi f;
bool pode[112345];

void fp(int k) {
	f.pb(1); f.pb(k);
	for (int i = 2; i*i <= k; i++) {
		if (k % i == 0) {
			f.pb(i);
			f.pb(k/i);
		}
	}
}
 
int main(int argc, char const *argv[]) { fastio;

	get4(a, b, c, d);

	if (c % a != 0) { cout1e(-1); return 0; }
	fp(c);

	// forita (it, f) cout << *it << " ";
	// cout << endl;

	int i = 0;
	forita (it, f) pode[i++] = true;

	i = 0;
	forita (it, f) {
		if (*it % a != 0 || *it % b == 0 || d % *it == 0) {
			pode[i] = false;
			// cout << "Removendo " << *it << endl;
		}
		i++;
	}

	i = 0; bool achou = false;
	forita (it, f) {
		if (pode[i++]) {
			cout1e(*it);
			achou = true;
			break;
		}
	}
	if (!achou) cout1e(-1);

	return 0;
}
