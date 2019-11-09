#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  string s;
  int c[10];

  for(int i = 0; i < 10; i++)
    c[i] = 0;

  cin >> n;

  for(int i = 0; i < n; i++)
  {
    cin >> s;
    for(int j = 0; j < s.size(); j++)
      c[s[j]-'0']++;
  }

  for(int i = 0; i < 10; i++)
    printf("%d - %d\n", i, c[i]);

  return 0;
}
