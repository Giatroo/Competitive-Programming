#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  if((a+b)/2 >= 7)
    cout << "Aprovado\n";
  else if((a+b)/2 >= 4)
    cout << "Recuperacao\n";
  else
    cout << "Reprovado\n";
  return 0;
}
