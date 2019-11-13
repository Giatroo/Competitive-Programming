#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int sa, na, sb, nb;
  int t[112345];
  int n;
  int l, r;

  sa = na = sb = nb = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", t+i);

  l = 0;
  r = n-1;
  while(l <= r)
  {
    if(sa <= sb){
      sa += t[l++];
      na++;
    } else {
      sb += t[r--];
      nb++;
    }
  }

  printf("%d %d\n", na, nb);

  return 0;
}
