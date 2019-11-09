#include <bits/stdc++.h>

using namespace std;

int Fib(int N)
{
  if(N == 0 || N == 1) return 1;
  return Fib(N-1) + Fib(N-2);
}

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  cout << Fib(N) << endl;
  return 0;
}
