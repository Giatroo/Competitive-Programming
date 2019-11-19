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

int main(int argc, char const *argv[]) {
  vector<ll> b, c;
  ll a;

  fora(i, 10) {
    cin >> a;
    if(a % 2 == 0) b.push_back(a);
    else c.push_back(a);
  }

  fora(i, b.size()) cout << b[i] << " ";
  cout << endl;
  fora(i, c.size()) cout << c[i] << " ";
  cout << endl;



  return 0;
}
