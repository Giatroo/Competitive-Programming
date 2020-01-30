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

ll cuts[3];
ll len;
ll pb[4123];

ll cuting(ll curlen) {
  ll tot = LLONG_MIN;
  ll a, b, c;
  if (curlen < 0) return LLONG_MIN;
  if (pb[curlen] != -1) return pb[curlen];

  a = cuting(curlen - cuts[0]);
  b = cuting(curlen - cuts[1]);
  c = cuting(curlen - cuts[2]);
  tot = max(a, b);
  tot = max(tot, c);
  tot++;
  return pb[curlen] = tot;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(len);
  get3(cuts[0], cuts[1], cuts[2]);
  fora(i, len + 5) pb[i] = -1;
  pb[0] = 0;
  cout1e(cuting(len));
  // fora(i, len + 3) cout2e(i, pb[i]);

  return 0;
}
