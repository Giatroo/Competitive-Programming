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
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

ll n, m;
ll x, y;
bool cat[212345];
vector<ll> adj[212345];
set<ll> leaves;
ll consec[212345];

void dfs(ll v) {
  stack<ll> st;
  forai(i, n) consec[i] = -1;
  st.push(v);
  consec[v] = (cat[v]) ? 1 : 0;

  while (!st.empty()) {
    v = st.top(); st.pop();
    if (consec[v] > m) continue;

    forita(it, adj[v]) {
      if (consec[*it] == -1) {
        consec[*it] = (cat[*it]) ? consec[v] + 1 : 0;
        st.push(*it);
      }
    }

    if (v != 1 && adj[v].size() == 1) leaves.insert(v);

  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  forai(i, n) { get1(x); cat[i] = (x == 1); }
  fora(i, n - 1) {
    get2(x, y);
    adj[x].pb(y);
    adj[y].pb(x);
  }

  dfs(1);
  cout1e(leaves.size());

  return 0;
}
