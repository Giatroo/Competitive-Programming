#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;
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

const int N = 112345;
const int L = 27;

int n;
vll adj[N];
int a, l;
int q;
int s, t;

int anc[N][L];
ll dp[N], dis[N];

void bfs() {
  int so;
  queue<int> q;
  q.push(0);
  fr (i, n) dp[i] = dis[i] = -1;
  dp[0] = dis[0] = 0;
  
  while (!q.empty()) {
    so = q.front(); q.pop();

    for (pii it : adj[so]) {
      if (dp[it.f] != -1) {
        anc[so][0] = it.f;
        continue;
      } 
      dp[it.f] = dp[so] + 1;
      dis[it.f] = dis[so] + it.s;
      q.push(it.f);
    }
  }
}

int lca(int u, int v) {
  if (dp[u] < dp[v]) swap(u, v);
  
  for (int i = L-1; i >= 0; i--) 
    if (dp[u] - (1 << i) >= dp[v]) u = anc[u][i];
  
  if (u == v) return u;

  for (int k = L-1; k >= 0; k--) {
    if (anc[u][k] != -1 && anc[v][k] != -1 && anc[u][k] != anc[v][k]) {
      u = anc[u][k];
      v = anc[v][k];
    }
  }

  return anc[u][0];
}

int main(int argc, char const *argv[]) { fastio;

  cin >> n;
  while (n) {
    frr (i, n-1) {
      cin >> a >> l;
      adj[a].pb(mk(i, l));
      adj[i].pb(mk(a, l));
    }

    fr (i, n) fr (j, L) anc[i][j] = -1;
    bfs();
    
    //cout << endl;
    //fr (i, n) 
    //  printf("i = %lld dis = %lld dp = %lld\n", i, dis[i], dp[i]);
    

    for (int j = 1; j < L; j++)
      for (int i = 1; i < n; i++) 
       if (anc[i][j-1] != -1) 
        anc[i][j] = anc[ anc[i][j-1] ][j-1];
      
    //cout << endl;
    //fr (i, n) {
    //  cout << "Linha " << i << ": ";
    //  fr (j, 6) {
    //    cout << anc[i][j] << " ";
    //  }
    //  cout << endl;
    //}

    cin >> q;
    fr (i, q) {
      cin >> s >> t;
      cout << dis[s] + dis[t] - 2*dis[lca(s, t)] << " ";
    }
    cout << endl;
    
    fr (i, n) adj[i].clear();

    cin >> n;
  }

  return 0;
}
