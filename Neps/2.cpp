#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int i;
  int t;
} Nadador;

Nadador n[3];

bool comp(Nadador n1, Nadador n2)
{
  return n1.t < n2.t;
}

int main(int argc, char const *argv[]) {
  n[0].i = 1;
  n[1].i = 2;
  n[2].i = 3;

  cin >> n[0].t >> n[1].t >> n[2].t;

  sort(n, n+3, comp);

  cout << n[0].i << endl << n[1].i << endl << n[2].i << endl;

  return 0;
}
