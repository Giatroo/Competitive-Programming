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

ll m[112];

int main(int argc, char const *argv[]) {
  int n;
  int a;
  int t = 0;
  char c;

  cin >> n;
  for(int i = 30; i <= 60; i++) m[i] = 0;

  fora(i, n) {
    cin >> a >> c;

    if (c == 'D') {
      if(m[a] > 0)
        t++;
      m[a]--;
    } else {
      if(m[a] < 0)
        t++;
      m[a]++;
    }
  }

  cout << t << endl;

  return 0;
}
