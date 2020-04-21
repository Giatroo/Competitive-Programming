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

int t, n, k;
int a[212345];
map<int, int> m;
int muda[412345];
int tot;

int main(int argc, char const *argv[]) { fastio;
	cin >> t;

	while (t--) {
		cin >> n >> k;
 		fr (i, n) cin >> a[i];
		m.clear();

		fr (i, n/2) m[a[i]+a[n-1-i]]++;
	
		muda[2] = n;
		for (int i = 3; i <= 2*k+1; i++) muda[i] = 0; 

		fr (i, n/2) {
			muda[min(a[i],a[n-1-i])+1]--;
			muda[max(a[i],a[n-1-i])+k+1]++;
			muda[a[i]+a[n-1-i]]--;
			muda[a[i]+a[n-1-i]+1]++;
		}

		tot = INF;
		for (int i = 2; i <= 2*k; i++) {
			muda[i] += muda[i-1]; 
			tot = min(tot, muda[i]);
		}
	
		if (m.size() == 1) { cout1e(0); continue; }

		cout << tot << endl;	
		
	}


  return 0;
}
