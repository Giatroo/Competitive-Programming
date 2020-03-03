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

ll n;
vector<ll> a;
map<ll, ll> m;
bool pointed[112];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  a.resize(n);
  fora (i, n) { get1(a[i]); pointed[i] = false; }
  sortvector(a);

  forita (it, a) {
    ll m2, d3;
    vector<ll>::iterator lm2, ld3;
    m2 = *it * 2;
    d3 = (*it % 3 == 0) ? *it / 3 : -1;
    lm2 = lower_bound(a.begin(), a.end(), m2);
    ld3 = lower_bound(a.begin(), a.end(), d3);

    if (*lm2 == m2) {
      m[*it] = lm2 - a.begin();
      pointed[lm2 - a.begin()] = true;
    } else if (*ld3 == d3){
      m[*it] = ld3 - a.begin();
      pointed[ld3 - a.begin()] = true;
    } else m[*it] = (ll)-1;
  }

  // forita (i, a) cout << *i << " ";
  // cout << endl;
  //
  // fora (i, n) cout << pointed[i] << " ";
  // cout << endl;
  //
  // forita (it, m) {
  //   cout3(it->f, "->", it->s);
  //   cout2e("",a[it->s]);
  // }

  ll start;
  fora (i, n) { if (!pointed[i]) { start = i; break; }}
  // cout1e(start);


  while (start != -1) {
    cout << a[start] << " ";
    start = m[a[start]];
  }
  cout << endl;

  return 0;
}
