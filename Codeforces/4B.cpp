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

using namespace std;

ll d, sumTime;
pair<ll, ll> times[40];
int memo[40][300]; //-1 -> not listed, 0 -> false, 1 -> true


//current day and current sum
int f(ll cd, ll cSum) {
  if (cd == d) return (cSum == sumTime) ? 1 : 0;

  if (memo[cd][cSum] == -1) {
    memo[cd][cSum] = 0;
    for (ll i = times[cd].f; i <= times[cd].s && memo[cd][cSum] == 0; i++)
      if (f(cd + 1, cSum + i) == 1) memo[cd][cSum] = 1;
  }

  // printf("memo[%lld][%lld] = %d\n", cd, cSum, memo[cd][cSum]);
  return memo[cd][cSum];
}

vector<ll> ans;

void recover(ll cd, ll cSum) {
  if (cd == d) return;

  ll flag = 0;
  for (ll i = times[cd].f; i <= times[cd].s && flag == 0; i++)
    if (f(cd + 1, cSum + i) == 1) {
      flag = 1;
      ans.pb(i);
      recover(cd+1, cSum + i);
    }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(d, sumTime);
  fora (i, d) get2(times[i].f, times[i].s);

  fora (i, d + 2) fora (j, sumTime + 3) memo[i][j] = -1;
  ll yn = f(0,0);
  if (yn == 1) {
    cout1e("YES");
    recover(0, 0);
    forita(it, ans) cout << *it << " ";
    cout << endl;
  } else cout1e("NO");

  return 0;
}
