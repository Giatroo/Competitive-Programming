#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
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
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

ll n, k, x;
ll a[212345];
ll p[212345];

ll uf[212345];
ll w[212345];
ll ind;

void build() {
  forai (i, n) {
    uf[i] = i;
    w[i] = 1;
  }
}

ll find(ll i) {
  return (uf[i] == i ? i : uf[i] = find(uf[i]));
}

void join(ll i, ll j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (w[i] < w[j]) swap(i, j);
  uf[j] = i;
  w[i] += w[j];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  build();
  forai (i, n) {
    get1(a[0]);
    a[a[0]] = i;
  }

  get1(k);
  fora (c, k) {
    forai (i, n) {
      get1(a[0]);
      join(a[0], i);
    }
  }

  get1(x);
  if (find(1) == find(a[x])) cout1e("YES");
  else cout1e("NO");

  return 0;
}
