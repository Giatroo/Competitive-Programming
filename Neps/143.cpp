#include <bits/stdc++.h>

using namespace std;

int main(){
  string s1, s2;
  int n, i, sum;

  sum = 0;

  scanf("%d", &n);
  cin >> s1 >> s2;

  for(i = 0; i < n; i++)
    if(s1[i] == s2[i]) sum++;

  printf("%d\n", sum);

  return 0;
}
