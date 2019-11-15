#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll A[112345];

int main()
{
  ll N, i;
  cin >> N;
  for(i = 0; i < N; i++)
    scanf("%lld", A+i);
  sort(A, A+N);

  for(i = 0; i < N-1; i++)
    printf("%lld ", A[i]);
  printf("%lld\n", A[i]);

  return 0;
}
