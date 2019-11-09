#include <bits/stdc++.h>

using namespace std;

bool in(char c, string s)
{
  for(int i = 0; i < s.size(); i++)
    if(c == s[i]) return true;
  return false;
}

int main()
{
  int i, j;
  string s;
  string vs = "aeiou";
  bool e = true;

  cin >> s;



  for (i = 0, j = s.size(); i <= j && e; )
  {
    if (!in(s[i], vs)) {
      i++;
      continue;
    }
    if (!in(s[j], vs)) {
      j--;
      continue;
    }

    //printf("s[%d] = %c  s[%d] = %c e = %d\n", i, s[i], j, s[j], e);
    e = (s[i] == s[j]);
    i++; j--;
  }

  if(e) cout << "S\n";
  else cout << "N\n";

  return 0;
}
