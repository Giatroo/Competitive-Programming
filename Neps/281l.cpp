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

ll n, m;
ll p[112345];
char q;
ll a, b;
ll t;

ll id[112345], sz[112345];

void create() {
  forai(i, n) { id[i] = i; sz[i] = 1; }
}

ll find(ll i) {
  if (id[i] == i) return i;
  return id[i] = find(id[i]);
}

void join(ll i, ll j) {
  i = find(i); j = find(j);
  if (i == j) return;
  if (sz[i] > sz[j]) { ll aux = i; i = j; j = aux; }
  id[i] = j;
  sz[j] += sz[i];
  p[j] += p[i];
}

bool luta(ll i, ll j) {
  ll k = find(1);
  i = find(i); j = find(j);
  if (k != i && k != j) return false;
  if (j == k) { ll aux = i; i = j; j = aux; }
  return p[i] > p[j];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  while (n * m != 0) {
    forai(i, n)
      cin >> p[i];
    create();
    t = 0;

    fora(i, m) {
      cin >> q >> a >> b;
      if (q == '1') join(a, b);
      else {
        t = luta(a, b) ? t + 1 : t;
      }

      // forai(i, n)
      //     cout << id[i] << " ";
      // cout << endl;
      // forai(i, n)
      //   cout << p[i] << " ";
      // cout << endl;
    }
    cout << t << endl;
    cin >> n >> m;
  }

  return 0;
}
