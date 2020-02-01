#include <iostream>
using namespace std;

int const N = 10e3;
int const M = 10e3;
int LCS[N][M]; // This is the DP table
int A[N], B[M]; // 1-index arrays of the problem
int n, m; //lenght of A and B respectively

int main() {
  // Input
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) cin >> B[i];

  // Base case
  for (int i = 0; i <= max(n, m); i++) LCS[i][0] = LCS[0][i] = 0;


  // The bottom-up solution
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
      if (A[i] == B[j]) LCS[i][j] = max(LCS[i][j], LCS[i-1][j-1] + 1);
    }
  }

  // See all the DP table
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //     cout << LCS[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // Outputing the solution
  cout << LCS[n][m] << endl;

  return 0;
}
