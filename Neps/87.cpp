#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  bool P, R;
  cin >> P >> R;

  if(P && R)
    cout << "A";
  else if(P && !R)
    cout << "B";
  else
    cout << "C";

  cout << endl;

  return 0;
}
