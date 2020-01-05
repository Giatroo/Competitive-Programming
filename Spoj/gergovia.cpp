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

ll n;
ll tot;
ll cur;
int a[112345];

void printArray(int n)
{
  fora(i, n) cout << a[i] << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  cin >> n;
  while(n != 0)
  {
    tot = 0;
    fora(i, n) cin >> a[i];

    cur = a[0];
    forai(i, n-1) {
        // printf("a[i] = %d cur = %lld tot = %lld\n", a[i], cur, tot);
        tot += abs(cur);
        cur += a[i];
    }

    cout << tot << endl;
    cin >> n;
  }
  return 0;
}
