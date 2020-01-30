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
#define M 1000000007

using namespace std;

ll n, m;
ll v[112345]; //1-indexed
ll t[412345][10]; //1-indexed
ll num[10];
ll cur, ant;

void build(ll l, ll r, ll i) {
  if (l == r)
    fora (j, 10) t[i][j] = (v[l] == j) ? 1 : 0;
  else {
    ll m = l + (r-l)/2;
    build(l, m, 2*i);
    build(m+1, r, 2*i+1);
    fora (j, 10) t[i][j] = t[2*i][j] + t[2*i+1][j];
  }
}

void query(ll l, ll r, ll i, ll ql, ll qr) {
  // printf("l = %lld r = %lld i = %lld ql = %lld qr = %lld\n", l, r, i, ql, qr);
  if (ql <= l && r <= qr) {
    fora (j, 10) num[j] += t[i][j];
    return;
  }
  if (qr < l || r < ql) return;

  ll m = l + (r-l)/2;
  query(l, m, 2*i, ql, qr);
  query(m+1, r, 2*i+1, ql, qr);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  forai (i, n) get1(v[i]);
  fora (i, 10) num[i] = 0;
  build(1, n, 1);

  get1(cur);
  num[v[cur]]++;
  fora (i, m-1) {
    ant = cur;
    get1(cur);
    query(1, n, 1, min(ant, cur), max(ant, cur));
    num[v[ant]]--;
  }

  fora (i, 10) cout << num[i] << " ";
  cout << endl;

  // forai (i, 4*n) {
  //   fora (j, 10) cout << t[i][j] << " ";
  //   cout << endl;
  // }
  // cout << endl;

  return 0;
}
