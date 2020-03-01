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

ll t, a, b, c, res, ans;
ll A, B, C;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  while (t--) {
    get3(a, b, c);
    ans = INF - 100;
    for (ll iA = 1; iA <= 2*a; iA++) {
      for (ll iB = iA; iB <= 2*b; iB += iA) {
        for (ll i = 0; i < 2; i++) {
          ll iC = iB * (c / iB) + i * iB;
          res = abs(iC - c) + abs(iB - b) + abs(iA - a);
          if (ans > res) {
            ans = res;
            A = iA; B = iB; C = iC;
          }
        }
      }
    }
    cout1e(ans);
    cout3e(A, B, C);
  }

  return 0;
}
