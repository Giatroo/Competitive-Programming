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

const int N = 20;
const int N15 = (1 << 15) + 50;
int n;
int a[N];
int memo[N][361];

bool dp(int i, int deg) {
  if (i == n)
     return deg % 360 == 0;

  int &dpm = memo[i][deg];
  if (dpm != -1) return dpm;

  int clock, anticlock;
  anticlock = (deg-a[i]); clock = (deg+a[i]);
  if (anticlock < 0) anticlock += 360;
  if (clock >= 360) clock -= 360;

  dpm = dp(i+1, clock) || dp(i+1, anticlock);

  return dpm;
}

int main(int argc, char const *argv[]) { fastio;
  cin >> n;
  fr (i, n) cin >> a[i];
  fr (i, N) fr (j, 360) memo[i][j] = -1;

  cout << (dp(0, 0) ? "YES" : "NO") << endl;

  return 0;
}
