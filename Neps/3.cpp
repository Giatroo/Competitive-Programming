#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b)
{
  if(a % b == 0) return b;
  else return gcd(b, a%b);
}

int main(int argc, char const *argv[]) {
  ll N, M;
  cin >> N >> M;

  for (ll i = M; i >= 1; i--)
    if(gcd(N, i) == 1)
    {
      printf("%lld\n", i);
      return 0;
    }

  printf("%d\n", 1);
  return 0;
}
