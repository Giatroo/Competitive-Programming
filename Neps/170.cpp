#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  double x;

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> x;
    cout << fixed << setprecision(4) << sqrt(x) << endl;
  }

  return 0;
}
