#include <bits/stdc++.h>
#include <queue>
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

const int L = 31;
const int N = 51234;

int n;
vi adj[N];
int c[N];
int anc[N][L];
int d[N];
int par[N];
int a, b;
int x;
ll soma;

void bfs(int s) {
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    s = q.front(); q.pop();
  
    for (auto it : adj[s]) {
      if (d[it] != -1) {
        anc[s][0] = it; 
        continue;
      }
      d[it] = d[s] + 1;
      q.push(it);
    }
  }
}

int lca(int i, int j) {
  if (d[i] < d[j]) swap(i, j);

  for (int k = L-1; k >= 0; k--) { 
    if (d[i] - (1<<k) >= d[j]) 
      i = anc[i][k];
  }
  
  if (i == j) return i;

  for (int k = L-1; k >= 0; k--) {
    if (anc[i][k] != 0 && anc[j][k] != 0 && anc[i][k] != anc[j][k]) {
      i = anc[i][k]; j = anc[j][k];
    }
  }
  return anc[i][0];
}

int main(int argc, char const *argv[]) { fastio;

  cin >> n;
  frr (i, n) {
    cin >> x;
    if (c[x]) {
      par[c[x]] = i;
      par[i] = c[x];
    }
    c[x] = i;
  }
  fr (i, n-1) { cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }
  frr (i, n) d[i] = -1;
  d[1] = 0;
  bfs(1);

  anc[1][0] = 0;
  frr (j, L-1) {
    frr (i, n) anc[i][j] = anc[ anc[i][j-1] ][j-1];
  }

  soma = 0;
  frr (i, n)  
    soma += (d[i] + d[par[i]] - 2*d[lca(i, par[i])]);

  cout1e(soma/2);

  return 0;
}
