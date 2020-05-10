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

const int N = 112;
const double EPS = 1E-7;
int distp[N], distb[N];
bool vis[N];
const double vp = 160.0;
int n, m, e;
bool saida[N];
int b, p, u, v, l;
vii adj[N];

void djsp() {
  set<pii> s;
  fr (i, n+2) distp[i] = INF;
  s.insert(mk(0, p));
  distp[p] = 0;
 
  pii p1; 
  while (!s.empty()) {
    p1 = *s.begin(); s.erase(s.begin());

    if (distp[p1.s] < p1.f) continue;
    for (auto it : adj[p1.s]) {
      if (distp[it.f] > distp[p1.s] + it.s) {
        distp[it.f] = distp[p1.s] + it.s;
        s.insert(mk(distp[it.f], it.f));
      }
    }
  }
}

void djsb() {
  set<pii> s;
  fr (i, n+2) distb[i] = INF;
  s.insert(mk(0, b));
  distb[b] = 0;
 
  pii p1; 
  while (!s.empty()) {
    p1 = *s.begin(); s.erase(s.begin());
    
    if (distb[p1.s] < p1.f) continue;
    for (auto it : adj[p1.s]) {
      if (distb[it.f] > distb[p1.s] + it.s) {
        distb[it.f] = distb[p1.s] + it.s;
        s.insert(mk(distb[it.f], it.f));
      }
    }
  }
}

bool dfs(double vel) {
  stack<int> st;
  st.push(b);
  fr (i, n+2) vis[i] = false;
  vis[b] = true;

  int cur;
  while (!st.empty()) {
    cur = st.top(); st.pop();
    if (saida[cur] == true) return true;
    for (auto it : adj[cur]) {
      if (!vis[it.f] && distp[it.f]/vp > distb[it.f]/vel) {
        st.push(it.f);
        vis[it.f] = true;
      }
    }
  }
  return false;
}

double bb(double l, double r) {
  double m;
  while (abs(r-l) >= EPS) {
    m = (l+r)/2;
    if (dfs(m)) r = m;
    else l = m;
  }
  if (m > 1e8) { cout1e("IMPOSSIBLE"); exit(0); }
  return m;
}

int main(int argc, char const *argv[]) { fastio;
  cin >> n >> m >> e;
  fr (i, m) {
    cin >> u >> v >> l;
    adj[u].pb(mk(v, l));
    adj[v].pb(mk(u, l));
  } 
  fr (i, n+2) saida[i] = false;
  fr (i, e) { cin >> u; saida[u] = true; }
  cin >> b >> p;
  djsb(); djsp();

  cout << setprecision(9) << fixed << bb(0, 1e9) << endl; 

  return 0;
}
