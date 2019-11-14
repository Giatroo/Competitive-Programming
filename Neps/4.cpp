#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
ll sum;
ll A[11234];

int main(int argc, char const *argv[]) {
  cin >> N >> M;
  for(int i = 0; i < N; i++)
    scanf("%lld", A+i);

  if (M - A[0] < A[0]) A[0] = M - A[0];

  for(int i = 1; i < N; i++)
  {
    if(M - A[i] < A[i]) A[i] = M - A[i];
    if(A[i-1] > A[i])
    {
      A[i] = M - A[i];
      if(A[i-1] > A[i])
      {
        printf("%d\n", -1);
        return 0;
      }
    }
  }

  sum = 0;

  for (int i = 0; i < N; i++)
    sum += A[i];

  printf("%lld\n", sum);


  return 0;
}
