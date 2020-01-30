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

pll p0, p1, q0, q1;
//0 -> mais à esquerda e mais para baixo

bool between(ll a, ll b, ll c) {
  return (a <= b && b <= c);
}

bool equals(pll pt1, pll pt2) {
  return (pt1.f == pt2.f && pt1.s == pt2.s);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(p0.f, p0.s);
  get2(p1.f, p1.s);
  get2(q0.f, q0.s);
  get2(q1.f, q1.s);

  if (equals(p0, q0) || equals(p0, q1) || equals(p1, q0) || equals(p1, q1))
  {
    cout1e(1);
    return 0;
  }

  if ((between(p0.f, q0.f, p1.f) && between(p0.s, q0.s, p1.s)) ||
      (between(p0.f, q1.f, p1.f) && between(p0.s, q1.s, p1.s)))
  {
    if ((between(p0.f, q0.f, p1.f) && between(p0.s, q0.s, p1.s)) &&
        (between(p0.f, q1.f, p1.f) && between(p0.s, q1.s, p1.s)))
        cout1e(0);
    else cout1e(1);
  } else cout1e(0);

  return 0;
}
