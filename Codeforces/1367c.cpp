#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define debug(x) #x << " = " << x << " "

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

int t, n, k;
string s;
int c, m, tot;

int main(int argc, char const *argv[]) { fastio;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    c = INF;
    m = -1;
    tot = 0;

    fr (i, s.size()) {
      if (m >= 0 && m == i-k-1) { s[m] = '1'; m = -1; tot++; }
      if (s[i] == '1') {
        c = 0;
        m = -1;
      }
      if (m == -1 && c >= k) m = i;
      if (s[i] == '0') c++;

      // cout << debug(i) << debug(c) << debug(m) << debug(i-k-1) << endl;
    }
    if (m >= 0) { s[m] = '1'; tot++; }
    // cout << s << endl;
    cout << tot << endl;
  }

  return 0;
}
