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
vector<ll> adj[212345];
ll d[212345]; //degree
ll t;

bool bfs(ll v) {
  stack<ll> st;
  bool compCy = true;
  if ((d[v] = adj[v].size()) != 2) compCy = false;
  st.push(v);

  while (!st.empty()) {
    v = st.top(); st.pop();
    forita(it, adj[v]) {
      if (d[*it] == -1) {
        if ((d[*it] = adj[*it].size()) != 2) compCy = false;
        st.push(*it);
      }
    }
  }
  return compCy;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  fora(i, m) {
    get2(x, y);
    adj[x].pb(y);
    adj[y].pb(x);
  }

  forai(i, n) d[i] = -1;
  t = 0;
  forai(i, n) {
    if (d[i] == -1) {
      if (bfs(i)) {
        t++;
        // cout << "t++ em " << i << endl;
      }
    }
  }

  cout1e(t);

  return 0;
}
