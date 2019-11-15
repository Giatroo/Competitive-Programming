#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;


int main(int argc, char const *argv[]) {
  ll L, C, r;
  cin >> L >> C;
  r = (L % 2 == 1);
  r += (C % 2 == 1) + 1;
  r %= 2;
  cout << r << endl;
  return 0;
}
