#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
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
vector<ll> adj[112];

bool dfs(ll v) {
  stack<ll> s;
  ll listed[112];
  forai(i, n) listed[i] = -1;
  s.push(v);
  listed[v] = 1;

  while (!s.empty()) {
    v = s.top();
    s.pop();

    forita(it, adj[v]) {
      if (listed[*it] == -1) {
        s.push(*it);
        listed[*it] = 1;
      }
    }
  }

  forai(i, n) if (listed[i] == -1) return false;
  return true;
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

  if (m == n && dfs(1)) cout << "FHTAGN!" << endl;
  else cout << "NO" << endl;

  return 0;
}
