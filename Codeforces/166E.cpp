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
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

/*ll dp[11234567][4];*/
ll dp[4][2];
ll n;

void add(ll &a, ll b) {
  a += b;
  if (a > M)
    a -= M;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);

  /*dp[0][0] = 1;
  dp[0][1] = dp[0][2] = dp[0][3] = 0;*/
  dp[0][1] = 1;
  dp[1][1] = dp[2][1] = dp[3][1] = 0;

  forai (i, n) {
    fora (j, 4) {
      dp[j][0] = 0;
      fora (k, 4) {
        if (j == k) continue;
        add(dp[j][0], dp[k][1]);
      }
    }
    fora (k, 4) dp[k][1] = dp[k][0];
  }

  cout1e(dp[0][0]);

  return 0;
}
