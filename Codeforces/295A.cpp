#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mk make_pair
#define coutp(a, b) cout << (a) << " " << (b)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

typedef struct {
  ll l, r, d;
} operation;

vector<pair<ll, ll>> queries;
vector<operation> operations;
ll n, m, k;
ll l, r, d;
ll x, y;
ll a[112345];
ll ps[112345];
operation o;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  forai(i, n) cin >> a[i];

  o.l = 0;
  o.r = 0;
  o.d = 0;
  operations.pb(o);
  
  forai(i, m) {
    cin >> l >> r >> d;
    o.l = l;
    o.r = r;
    o.d = d;
    operations.pb(o);
  }

  forai(i, m) ps[i] = 0;

  forai(i, k) {
    cin >> x >> y;
    ps[x]++;
    ps[y+1]--;
  }

  ps[0] = 0;
  forai(i, m) ps[i] += ps[i-1];

  forai(i, m) operations[i].d *= ps[i];

  forai(i, n) ps[i] = 0;
  forai(i, m) {
    ps[operations[i].l] += operations[i].d;
    ps[operations[i].r+1] -= operations[i].d;
  }
  ps[0] = 0;
  forai(i, n) ps[i] += ps[i-1];

  forai(i, n) cout << a[i] + ps[i] << " ";
  cout << endl;



  return 0;
}
