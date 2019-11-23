#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

pair<int, int> q[512345];
ll n;
bool m;

int main(int argc, char const *argv[]) {
  cin >> n;
  m = false;
  fora(i, n)
    cin >> q[i].f >> q[i].s;

  sort(q, q+n);

  fora(i, n-1)
  {
    if(q[i].f == q[i+1].f && q[i].s == q[i+1].s){
      m = true; break;
    }
  }

  if(m) cout << 1 << endl;
  else cout << 0 << endl;


  return 0;
}
