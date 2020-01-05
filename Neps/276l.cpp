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
#define forita(c) for(auto it = c.begin(); it != c.end(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n, d;
ll aux;
ll t = 0;
ll l, r;
vector<ll> c(2123456);
vector<ll> v(1123456);


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d;

  fora(i, n) {
    cin >> aux;
    v[i] = aux;
  }

  c[0] = v[0];
  forai(i, 2*n-1)
    c[i] = c[i-1] + v[i % n];


  if(c[n-1] < d) {
    cout << 0 << endl;
    return 0;
  }

  l = r = 0;

  fora(l, n) {
    while(r < 2*n && c[r] - c[l] < d) r++;
    if(c[r] - c[l] == d) t++;
  }

  cout << t << endl;



  return 0;
}
