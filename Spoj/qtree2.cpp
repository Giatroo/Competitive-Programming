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

const int N = 11234;
const int L = 27;
int n, u, v, w;
string s;

int dist[N];
int dp[N];
int acm[N][L];
vii adj[N];

int l, t;

void bfs() {
  int s;
  queue<int> q;
  q.push(1);
  dp[1] = dist[1] = 0;

  while (!q.empty()) {
    s = q.front(); q.pop();
    for (pii it : adj[s]) {
      if (dp[it.f] != -1) { acm[s][0] = it.f; continue; }
      dp[it.f] = dp[s] + 1;
      dist[it.f] = dist[s] + it.s;
      q.push(it.f);
    }
  }
}

int lca(int a, int b) {
  if (dp[a] < dp[b]) swap(a, b);
  for (int j = L-1; j >= 0; j--) {
     if (dp[a] - (1<<j) >= dp[b]) a = acm[a][j];
  }
  if (a == b) return a;
  for (int j = L-1; j >= 0; j--) {
    if (acm[a][j] != acm[b][j]) { a = acm[a][j]; b = acm[b][j]; }
  }
  return acm[a][0];
}

int kth(int a, int k) {
  for (int i = L-1; i >= 0; i--) {
    if (1<<i & k) a = acm[a][i];
  }
  return a;
} 

int main(int argc, char const *argv[]) { fastio;
  cin >> t;

  while (t--) { 

  cin >> n;

  fr (i, n-1) {
    cin >> u >> v >> w;
    adj[u].pb(mk(v, w));
    adj[v].pb(mk(u, w));
  }
  fr (i, n+1) fr (j, L) acm[i][j] = 0;
  fr (i, n+1) dp[i] = -1;
  bfs();
  frr (j, L-1) frr (i, n) acm[i][j] = acm[acm[i][j-1]][j-1];

  cin >> s;
  while (s != "DONE") {
    if (s == "DIST") {
      cin >> u >> v;
      cout << dist[u] + dist[v] - 2*dist[lca(u, v)] << endl;
    } else {
      cin >> u >> v >> w;
      l = lca(u, v);
      if (w <= dp[u]-dp[l]) cout1e(kth(u,w-1));  
      else cout1e(kth(v, dp[u]+dp[v]-2*dp[l]-w+1));
    } 
    cin >> s;
  }
  fr (i, n+1) adj[i].clear();
  }

  return 0;
}
