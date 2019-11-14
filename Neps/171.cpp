#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

ll n;
ll t;
int a[] = {100, 50, 25, 10, 5, 1};

int main(int argc, char const *argv[]) {
  scanf("%lld", &n);
  t = 0;
  for(int i = 0; i < 6; i++)
  {
    t += n / a[i];
    n %= a[i];
  }

  printf("%lld\n", t);

  return 0;
}
