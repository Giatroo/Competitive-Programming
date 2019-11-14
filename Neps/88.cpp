#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  if(a+b+c == 2)
  {
    if(!a) printf("A");
    if(!b) printf("B");
    if(!c) printf("C");
  } else if(a+b+c == 1)
  {
    if(a) printf("A");
    if(b) printf("B");
    if(c) printf("C");
  } else printf("*");

  printf("\n");

  return 0;
}
