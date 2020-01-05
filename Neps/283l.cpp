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
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n, k;
ll id[112345], sz[112345];

void create() {
  fora(i, n) { id[i] = i; sz[i] = 1; }
}

ll find(ll i) {
  if (id[i] == i) return i;
  return id[i] = find(id[i]);
}

void join(ll i, ll j) {
  i = find(i); j = find(j);
  if (i == j) return;
  if (sz[i] > sz[j]) {
    ll aux = i; i = j; j = aux;
  }
  //A partir daqui, i tem o menor tamanho
  id[i] = j;
  sz[j] += sz[i];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll p, q; char c;
  cin >> n >> k;
  create();
  fora(i, k) {
    cin >> c >> p >> q;
    if (c == 'C') {
      if (find(p) == find(q)) cout << "S" << endl;
      else cout << "N" << endl;
    }
    else join(p, q);
  }

  return 0;
}
