#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

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

const int N = 1123;

int dp[4*N];
int ind[N];
int nodes[4*N];
pii st[4*N];

vi adj[N];
int u, v;
int t, q, n, m;
int a, b;

void build(int i, int l, int r) {
  if (l == r) {
    st[i] = mk(dp[l], l);
  } else {
    int m = l + (r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    st[i] = (st[2*i].f <= st[2*i+1].f ? st[2*i] : st[2*i+1]); 
  }
}

pii query(int i, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return st[i]; 
  if (l > qr || r < ql) return mk(INF, -1);

  int m = l + (r-l)/2;
  pii q1, q2;
  q1 = query(2*i, l, m, ql, qr);
  q2 = query(2*i+1, m+1, r, ql, qr);
  return (q1.f <= q2.f ? q1 : q2);
}

int timer;
void euler(int s, int depth) {
  nodes[timer] = s;
  ind[s] = timer;
  dp[timer] = depth;
  timer++;
  for (int i : adj[s]) {
    euler(i, depth+1);
    nodes[timer] = s;
    ind[s] = timer;
    dp[timer] = depth;
    timer++;
  }
}

int main(int argc, char const *argv[]) { fastio;
  cin >> t;
  int c = 1;
  while (t--) {
    cout << "Case " << c++ << ":" << endl;
    cin >> n;
    frr (i, n) {
      cin >> m;
      fr (j, m) {
        cin >> u;
        adj[i].pb(u);
      }
    }

    timer = 1;
    euler(1, 0);
    build(1, 1, timer-1); 

    cin >> q;
    fr (i, q) {
      cin >> u >> v;
      a = min(ind[u], ind[v]);
      b = max(ind[u], ind[v]);
      cout << nodes[query(1, 1, timer-1, a, b).s] << endl;
    }

    frr (i, n) adj[i].clear();
  }

  return 0;
}
