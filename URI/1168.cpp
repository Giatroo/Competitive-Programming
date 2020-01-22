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

ll n;
string s;
ll tot;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  fora (i, n) {
    get1(s);
    tot  = 0;
    fora (j, s.size()) {
      switch (s[j]) {
        case '0':
        case '9':
        case '6':
          tot += 6;
        break;

        case '1':
          tot += 2;
        break;

        case '8':
          tot += 7;
        break;

        case '7':
          tot += 3;
        break;

        case '4':
          tot += 4;
        break;

        case '5':
        case '2':
        case '3':
          tot += 5;
        break;
      }
    }

    cout2e(tot, "leds");
  }

  return 0;
}
