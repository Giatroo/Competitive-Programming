#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

const int N = 112345;

ll n, k;
ll a, b;
char c;
string ans;
ll segtree[412345]; //1-indexed
ll arr[112345];

void createSeg(ll l, ll r, ll pos) {
  if (l == r) {
		segtree[pos] = arr[l];
		if (segtree[pos] > 0) segtree[pos] = 1;
		else if (segtree[pos] < 0) segtree[pos] = -1;
		return;
	}

  ll m = l + (r-l)/2;
  createSeg(l, m, 2*pos);
  createSeg(m+1, r, 2*pos+1);
  segtree[pos] = segtree[2*pos] * segtree[2*pos+1];
}

ll querry(ll l, ll r, ll pos) {
  if (a <= l && r <= b) return segtree[pos];
  if (l > b || r < a) return 1;

  ll m = l + (r-l)/2;

  return querry(l, m, 2*pos) *
         querry(m+1, r, 2*pos+1);
}

void update(ll l, ll r, ll pos) {
  if (l == r) {
		segtree[pos] = b;
		if (segtree[pos] > 0) segtree[pos] = 1;
		else if (segtree[pos] < 0) segtree[pos] = -1;
	}
  else {
    ll m = l + (r-l)/2;
    if (a <= m) update(l, m, 2*pos);
    else update(m+1, r, 2*pos+1);
    segtree[pos] = segtree[2*pos] * segtree[2*pos+1];
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (get2(n, k)) {
    forai (i, n) get1(arr[i]);
    createSeg(1, n, 1);

    ans = "";
    fora (i, k) {
      get3(c, a, b);
      if (c == 'P') {
        ll r = querry(1, n, 1);
        if (r == 0) ans += "0";
        else if (r > 0) ans += "+";
        else ans += "-";
      } else update(1, n, 1);
    }

    cout1e(ans);
  }

  return 0;
}
