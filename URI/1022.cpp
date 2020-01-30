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
#define M 1000000007

using namespace std;

ll t;
ll n1, n2, d1, d2;
ll n3, n4, d3, d4;
ll m;
char op;
char dummy;

ll mdc(ll a, ll b) {
  return (b == 0) ? a : mdc(b, a%b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  fora (i, t) {
    get3(n1, dummy, d1);
    get1(op);
    get3(n2, dummy, d2);
    switch (op) {
      case '+':
      n3 = n1*d2 + n2*d1;
      d3 = d1*d2;
      break;
      case '-':
      n3 = n1*d2 - n2*d1;
      d3 = d1*d2;
      break;
      case '*':
      n3 = n1*n2;
      d3 = d1*d2;
      break;
      case '/':
      n3 = n1*d2;
      d3 = n2*d1;
      break;
    }
    m = mdc(n3, d3);
    n4 = n3 / m;
    d4 = d3 / m;

    if (d4 <= 0) { d4 *= -1; n4 *= -1; }

    printf("%lld/%lld = %lld/%lld\n", n3, d3, n4, d4);
  }

  return 0;
}
