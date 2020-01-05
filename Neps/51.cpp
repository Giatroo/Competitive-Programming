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

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

int main(int argc, char const *argv[]) {
  int p;
  int s, a;
  s = 0;
  cin >> p;
  cin >> s;
  cin >> a;
  s += a;
  if(s % 2 == 0){
    if(p == 0) cout << 0 << endl;
    else cout << 1 << endl;
  } else {
    if(p == 0) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}
