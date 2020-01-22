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
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

ll c, f;
ll dp[1123][61];
ll n[1123], d[1123];
ll t;

ll knapsack(ll cur, ll car) {
  // cout2e(cur, car);
  if (car < 0) return MINF;
  if (cur == f) return 0;

  ll &mem = dp[car][cur];
  if (mem != -1) return mem;

  return mem = max(knapsack(cur+1, car), d[cur] + knapsack(cur+1, car-n[cur]));
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(c, f);
  t = 1;

  while (c * f != 0) {
    fora (i, f) get2(n[i], d[i]);
    fora (i, c+4) fora (j, f+3) dp[i][j] = -1;
    cout2e("Teste", t++);
    cout1e(knapsack(0, c));
    cout << endl;

    get2(c, f);
  }

  return 0;
}
