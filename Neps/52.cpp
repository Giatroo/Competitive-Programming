#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int v1, v2;
  int i1, i2;
  int aux;

  v1 = v2 = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    scanf("%d", &aux);
    if(aux == 1) v1++;
    else v2++;
  }

  i1 = !(v1 % 2 == 0);
  i2 = !(v2 % 2 == 0);

  if(v2 % 2 != 0)
    i1 = (i1 + 1) % 2;


  printf("%d\n%d\n", i1, i2);

  return 0;
}
