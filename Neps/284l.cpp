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

ll n, l;
priority_queue<pair<ll, ll>> pq;
pair<ll, ll> v;
ll t;
ll vendedor[1123];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l;
  forai(i, n) vendedor[i] = 0;
  forai(i, n) pq.push(mk(0, -i));

  fora(i, l) {
    cin >> t;
    v = pq.top();
    pq.pop();
    // coutp(-v.f, -v.s) << endl;
    vendedor[-v.s]++;
    pq.push(mk(-(-v.f + t), v.s));
  }

  forai(i, n)
    coutp(i, vendedor[i]) << endl;

  return 0;
}
