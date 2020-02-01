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

int DP[112345][1123];
int S[1123];

int K, C;

int change(int c, int k) {
  if (c < 0 || k > K) return 0;
  if (c == 0) return 1;

  int &d = DP[c][k];
  if (d != -1) return d;

  return d = ((change(c, k+1) == 1 || change(c-S[k], k+1) == 1) ? 1 : 0);
}

int main() {
  cin >> C >> K;
  for (int i = 0; i < K; i++) cin >> S[i];

  for (int i = 0; i <= C; i++)
    for (int j = 0; j < K; j++)
      DP[i][j] = -1;

  cout << (change(C, 0) == 1 ? "S" : "N") << endl;
  return 0;
}
