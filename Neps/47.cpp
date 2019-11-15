#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;

ll N, sum;
ll a[11234];

int main(int argc, char const *argv[]) {
  cin >> N;
  sum = 0;
  fora(i, N) cin >> a[i];

  fora(i, N-2)
    if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 0)
      sum++;

  printf("%lld\n", sum);

  return 0;
}
