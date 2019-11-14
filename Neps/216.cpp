#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for(int i = 1; i < N; i++)
    if(N % i == 0) printf("%d ", i);
  printf("%d\n", N);
  return 0;
}
