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
const int L = 12;
int t, n, m, q;
int v, w;

vi adj[N];
int anc[N][L];
int dp[N];

void bfs() {
  queue<int> q;
  q.push(1);
  frr (i, n) dp[i] = -1;
  dp[1] = 0;

  int s;
  while (!q.empty()) {
    s = q.front(); q.pop();
    for (int i : adj[s]) {
      if (dp[i] != -1) {
        anc[s][0] = i;
        continue;
      }
      dp[i] = dp[s] + 1;
      q.push(i);  
    }
  }
}

int lca(int u, int v) {
  if (dp[u] < dp[v]) swap(u, v);
  for (int i = L-1; i >= 0; i--) 
    if (dp[u]-(1<<i)>=dp[v]) u = anc[u][i];
  
  if (u == v) return u;

  for (int i = L-1; i >= 0; i--) {
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i]; v = anc[v][i];
    }
  }
  return anc[u][0];
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
        cin >> v;
        adj[v].pb(i);
        adj[i].pb(v);
      }
    }

    fr (i, n+2) fr (j, L) anc[i][j] = 0;
    bfs();

    frr (j, L-1) frr (i, n) 
        anc[i][j] = anc[anc[i][j-1]][j-1];

    cin >> q;
    fr (k, q) {
      cin >> v >> w;
      cout1e(lca(v, w)); 
    }
    
    frr (i, n) adj[i].clear();
  }
  
  return 0;
}
