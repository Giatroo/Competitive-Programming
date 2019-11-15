#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll A[112345];
ll B[112345];
ll C[112345];

int main()
{
  ll N, i, j, counter;

  cin >> N;

  for(i = 0; i < N; i++){
    scanf("%lld", A+i);
    B[i] = A[i];
  }

  sort(A, A+N);

  for(i = 0, j = 0, counter = 0; i < N; i++)
    if(A[i] != B[i]){
      counter++;
      C[j++] = B[i];
    }

  sort(C, C+counter);
  printf("%lld\n", counter);
  for(j = 0; j < counter-1; j++)
    printf("%lld ", C[j]);
  if(counter != 0)
    printf("%lld\n", C[j]);

  return 0;
}
