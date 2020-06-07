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

int n, f;
int c[112345];

int tot(int k) {
  int ret = 0;
  fr (i, n) ret += (k/c[i]);
  return ret;
}

int bb() {
  int l, m, r;
  int totm;
  int mini;
  l = 0; r = 1e8+5;
  m = l + (r-l)/2;
  mini = r;

  while (l <= r) {
    m = l + (r-l)/2;
    totm = tot(m);
    if (totm >= f) {
      mini = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }
  return mini;
}

int main(int argc, char const *argv[]) { fastio;
  cin >> n >> f;
  fr (i, n) cin >> c[i];
  cout << bb() << endl;

  return 0;
}
