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

int const N = 10e3;
bool DP[N][11];
int S[N];
// k is the number of coins
// L is the limit of coins we can use
bool change(int C, int k, int L) {
  for (int i = 1; i <= C; i++)
    for (int j = 0; j <= L; j++)
      DP[i][j] = false;

  for (int j = 0; j < L; j++)
    DP[0][j] = true;

  for (int i = 1; i <= C; i++) {
    for (int I = 1; I < L; I++) {
      for (int j = 0; j < k && !DP[i][I]; j++) {
        if (i - S[j] < 0) continue;
        DP[i][I] = DP[i - S[j]][I-1];
        // As soon DP[i] become true, we leave the for
      }
    }
  }

  for (int i = 0; i < L; i++) if (DP[C][i]) return true;
  return false;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, C;
  get2(k, C);
  fora (i, k) get1(S[i]);
  cout << (change(C, k, 10) ? "S" : "N") << endl;

  return 0;
}
