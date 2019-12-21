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

vector<ll> adj[112345];
ll pecas[112345];
ll n, x, y;

ll numPecas(ll i) {
  ll num = 1;
  forita(it, adj[i]) //base -> lista vazia (folhas)
    num += numPecas(*it);
  return pecas[i] = num;
}

bool bfs(ll fonte) {
  queue<ll> fila;
  ll num;
  fila.push(fonte);

  while (!fila.empty()) {
    fonte = fila.front();
    fila.pop();

    if (adj[fonte].size() != 0) {
      num = pecas[adj[fonte][0]];
      forita (it, adj[fonte]) {
        if (pecas[*it] != num) return false;
        fila.push(*it);
      }
    }
  }

  return true;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora(i, n) {
    get2(x, y);
    adj[y].pb(x);
  }

  numPecas(0);

  if (bfs(0)) cout1e("bem");
  else cout1e("mal");

  return 0;
}
