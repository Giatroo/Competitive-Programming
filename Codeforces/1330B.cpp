#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define cout1e(a) cout << (a) << endl
#define cout2e(a, b) cout << (a) << " " << (b) << endl
#define cout3e(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define cout4e(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define debug(x) cout << #x << " = " << x << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

int t, n;
int a[212345];
bool nums[212345];
set<int> per;
int lida, lvolta;

int main(int argc, char const *argv[]) { fastio;

  cin >> t;
  while (t--) {
    cin >> n;
    fr (i, n) get1(a[i]);
    lida = lvolta = -1;

    per.clear();
    // ida
    fr (i, n) {
      if (per.count(a[i])) {
        lida = i;
        break;
      }
      per.insert(a[i]);
    }

    frr (i, lida) nums[i] = false;
    fr (i, lida) nums[a[i]] = true;
    frr (i, lida) {
      if (!nums[i]) {
        lida = -1;
        break;
      }
    }
    frr (i, n-lida+2) nums[i] = false;
    for (int i = lida; i < n; i++) nums[a[i]] = true;
    frr (i, n-lida) {
      if (!nums[i]) {
        lida = -1;
        break;
      }
    }
    per.clear();
    // volta
    for (int i = n-1; i >= 0; i--) {
      if (per.count(a[i])) {
        lvolta = i+1;
        break;
      }
      per.insert(a[i]);
    }

    frr (i, lvolta) nums[i] = false;
    fr (i, lvolta) nums[a[i]] = true;
    frr (i, lvolta) {
      if (!nums[i]) {
        lvolta = -1;
        break;
      }
    }
    frr (i, n-lvolta+2) nums[i] = false;
    for (int i = lvolta; i < n; i++) nums[a[i]] = true;
    frr (i, n-lvolta) {
      if (!nums[i]) {
        lvolta = -1;
        break;
      }
    }

    if (lida == lvolta) lvolta = -1;


    if (lida != -1 && lvolta != -1) {
      cout1e(2);
      cout2e(lida, n-lida);
      cout2e(lvolta, n-lvolta);
    } else if (lida != -1) {
      cout1e(1);
      cout2e(lida, n-lida);
    } else if (lvolta != -1) {
      cout1e(1);
      cout2e(lvolta, n-lvolta);
    } else {
      cout1e(0);
    }

  }

  return 0;
}
