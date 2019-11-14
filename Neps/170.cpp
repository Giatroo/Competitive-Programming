#include <bits/stdc++.h>

using namespace std;

int N, M;
int f[1123];
int T;
int d;

int main(int argc, char const *argv[]) {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++)
    scanf("%d", f+i);

  T = 0;
  for(int i = 0; i < N-1; i++)
  {
    d = M - f[i];
    T += abs(d);
    f[i] += d;
    f[i+1] += d;
  }

  printf("%d\n", T);


  return 0;
}
