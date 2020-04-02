#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
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

int n, a, b;
string s, t;
int k;

struct cpms {
	bool operator()(pii p1, pii p2) {
		if (p1.f == p1.s) return true;
		if (p2.f == p2.s) return false;
		return true;
	}
};

set<int> sa, sb;
set<pii , cpms > sk;

int main(int argc, char const *argv[]) { fastio;

	get1(n);
	get2(s, t);
	
	a = b = 0;

	fr (i, n) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') { a++; sa.insert(i); }
			else { b++; sb.insert(i); }
		}
	}

	// a

	k = a/2;
	a %= 2;
	int a1, a2;	
	fr (i, k) {
		auto it = sa.begin();
		a1 = *it; it++;
		a2 = *it;
		sk.insert(mk(a1, a2));
		sa.erase(sa.begin());
		sa.erase(sa.begin());
	}

	// b
	k = b/2;
	b %= 2;
	int b1, b2;	
	fr (i, k) {
		auto it = sb.begin();
		b1 = *it; it++;
	  b2 = *it;
		sk.insert(mk(b1, b2));
		sb.erase(sb.begin());
		sb.erase(sb.begin());
	}
	
	if (sa.size() == sb.size()) {
		if (sa.size() == 1) {
			sk.insert(mk(*sa.begin(), *sa.begin()));
			sk.insert(mk(*sa.begin(), *sb.begin()));
		}
	} else {
		cout1e(-1);
		return 0;
	}

	cout1e(sk.size());
	forita (it, sk) cout2e(it->f+1, it->s+1);



	return 0;
}














