#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  int aux, sum;
  cin >> N;
  sum = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> aux;
    sum += aux;
  }
  cout << sum << endl;
  return 0;
}
