#include <bits/stdc++.h>

using namespace std;

int main(){
  int p1, p2, c1, c2;
  int r1, r2;
  cin >> p1 >> c1 >> p2 >> c2;
  r1 = p1*c1;
  r2 = p2*c2;
  if(r1 == r2) cout << 0;
  else if(r1 > r2) cout << -1;
  else cout << 1;
  cout << endl;
  return 0;
}