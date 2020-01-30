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
#define get1(a) cin >> (a) >> ws
#define get2(a, b) cin >> (a) >> (b) >> ws
#define get3(a, b, c) cin >> (a) >> (b) >> (c) >> ws
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d) >> ws
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

ll pbv[50];
ll pbc[50];

ll n, x;
ll fib;

ll f(ll i) {
  if (pbv[i] != -1) {
    return pbv[i];
  }
  if (i == 1 || i == 0) { pbc[i] = 0; return pbv[i] = i; }
  pbv[i] = f(i-1) + f(i-2);
  pbc[i] = 2 + pbc[i-1] + pbc[i-2];
  return pbv[i];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora (j, n) {
    cin >> x;
    fora (i, x+1) pbv[i] = pbc[i] = -1;
    f(x);
    printf("fib(%lld) = %lld calls = %lld\n", x, pbc[x], pbv[x]);
  }

  return 0;
}
