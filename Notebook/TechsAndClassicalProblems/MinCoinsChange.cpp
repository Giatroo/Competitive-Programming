#include <iostream>
using namespace std;

int const N = 10e5;
int DP[N];
int S[N];

int change(int C, int k) {
  for (int i = 0; i <= C; i++) DP[i] = C + 1; //placeholder

  DP[0] = 0; //base case
  // other cases:
  for (int i = 1; i  <= C; i++)
    for (int j = 0; j < k; j++)
      if (i - S[j] >= 0)
        DP[i] = min(DP[i - S[j]] + 1, DP[i]);

  return DP[C];
}

int main() {
  int C, k;
  cin >> C >> k;
  for (int i = 0; i < k; i++) cin >> S[i];
  cout << change(C, k) << endl;
  for (int i = 0; i <= C; i++) cout << i << " " << DP[i] << endl;
  return 0;
}
