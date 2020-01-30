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
#define pll pair<ll, ll>
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
#define INF INT_MAX

using namespace std;

ll n;
ll mina[112][112];
ll dist[112][112];
pll mov[4];

void dijkstra(pll S) {
  set<pair<ll, pll>> f;
  pair<ll, pll> aux;
  forai(i, n) forai(j, n) dist[i][j] = INF;
  f.insert(mk(0, S));

  while(!f.empty()) {
    aux = *f.begin(); f.erase(f.begin());
    if (dist[aux.s.f][aux.s.s] != INF) continue;
    // cout << "Olhando " << aux.s.f << " " << aux.s.s << endl;
    dist[aux.s.f][aux.s.s] = aux.f;

    fora(i, 4) {
      pll listing = mk(aux.s.f + mov[i].f, aux.s.s + mov[i].s);
      if (dist[listing.f][listing.s] >
          dist[aux.s.f][aux.s.s] + mina[listing.f][listing.s])
        f.insert(mk(dist[aux.s.f][aux.s.s] + mina[listing.f][listing.s], listing));
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora(i, n + 2) fora(j, n + 2) mina[i][j] = 0;
  forai(i, n) forai(j, n) get1(mina[i][j]);
  mov[0] = mk(0, 1);
  mov[1] = mk(0, -1);
  mov[2] = mk(1, 0);
  mov[3] = mk(-1, 0);

  dijkstra(mk(1, 1));
  cout << dist[n][n] << endl;

  return 0;
}
