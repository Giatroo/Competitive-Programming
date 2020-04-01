#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll N;
ll a[11234];
ll j;

int main(int argc, char const *argv[]) {
  cin >> N;
  fora(i, N) cin >> a[i];

  fora(i, N)
  {
    j = 0;
    while(1)
    {
      if(j+i < N && a[i+j] == 0) break;
      if(i-j >= 0 && a[i-j] == 0) break;
      j++;
    }

    a[i] = min(j, (ll) 9);
  }

  fora(i, N-1) cout << a[i] << " ";
  cout << a[N-1] << endl;

  return 0;
}
