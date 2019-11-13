#include <bits/stdc++.h>

using namespace std;

int c[1123];
int n;
int i;
int l, r;
int sa, sb;

int main(int argc, char const *argv[]) {
  scanf("%d", &n);

  for(i = 0; i < n; i++) scanf("%d", c+i);

  sa = sb = 0;
  l = 0; r = n-1;

  while(l <= r)
  {
    if(c[l] > c[r]) sa += c[l++];
    else sa += c[r--];

    if(l > r) break;

    if(c[l] > c[r]) sb += c[l++];
    else sb += c[r--];
  }

  printf("%d %d\n", sa, sb);

  return 0;
}
