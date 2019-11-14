#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, aux, sum;
    cin >> N;
    sum = 0;
    for(int i = 1; i <= N; i++)
    {
      cin >> aux;
      sum += aux;
      if(sum >= 1000000)
      {
        cout << i << endl;
        break;
      }
    }
    return 0;
}
