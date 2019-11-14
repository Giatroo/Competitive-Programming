#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

ll c[112345];
ll N;
ll sum;

ll bb(ll i)
{
  ll v = sum - c[i]; //Busco v, i é o índice de onde estou
  ll l, r, m;
  l = i; r = N-1;
  m = (l + r) / 2;

  while(l <= r)
  {
    if(c[m] == v) return m;
    if(c[m] > v) r = m - 1;
    else l = m + 1;
    m = (l+r)/2;
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  ll j;

  cin >> N;
  fora(i, N)
    scanf("%lld", c+i);

  cin >> sum;

  fora(i, N)
  {
    j = bb(i);
    if(j != -1)
    {
      printf("%lld %lld\n", c[i], c[j]);
      break;
    }
  }

  return 0;
}
