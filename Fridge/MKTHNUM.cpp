#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

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

const int N = 112345;

vector<ll> seg[4*N];
vector<ll> queryans1, queryans2;
ll arr[N];
ll n, m;
ll a, b, k;

void build(ll i, ll l, ll r) {
  if (l == r) {
    seg[i].pb(arr[l]);
  } else {
    ll m = l + (r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);

    merge(seg[2*i].begin(), seg[2*i].end(),
          seg[2*i+1].begin(), seg[2*i+1].end(),
          back_inserter(seg[i]));
  }
}

void querry(ll i, ll l, ll r, ll ql, ll qr) {
  if (r < ql || l > qr) return;

  if (ql <= l && r <= qr) {
    if (queryans1.empty()) {
      merge(seg[i].begin(), seg[i].end(),
            queryans2.begin(), queryans2.end(),
            back_inserter(queryans1));
      queryans2.clear();
    } else {
      merge(seg[i].begin(), seg[i].end(),
            queryans1.begin(), queryans1.end(),
            back_inserter(queryans2));
      queryans1.clear();
    }
    return;
  }

  ll m = l + (r-l)/2;
  querry(2*i, l, m, ql, qr);
  querry(2*i+1, m+1, r, ql, qr);
}

int main(int argc, char const *argv[]) { fastio;

  get2(n, m);
  frr (i, n) get1(arr[i]);
  build(1, 1, n);

  fr (i, m) {
    get3(a, b, k);
    queryans1.clear();
    queryans2.clear();
    querry(1, 1, n, a, b);

    // cout << "Final\n";
    // cout << "Primeiro: ";
    // fr (j, queryans1.size()) cout << queryans1[j] << " ";
    // cout << endl;
    // cout << "Segundo: ";
    // fr (j, queryans2.size()) cout << queryans2[j] << " ";
    // cout << endl << endl;

    if (queryans2.empty()) cout1e(queryans1[k-1]);
    else cout1e(queryans2[k-1]);

  }


  return 0;
}
