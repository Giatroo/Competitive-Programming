#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  for(int i = 1; N != 0; i++)
  {
    printf("Teste %d\n%d\n\n", i, (int) (pow(2, N)-1));
    cin >> N;
  }
  return 0;
}
