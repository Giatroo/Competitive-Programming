#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct {
  ll ini;
  ll fim;
} Inter;

Inter inters[212345];
ll n, h;
ll l, r;
ll ir;
ll maxim;
ll i;

int main(int argc, char const *argv[]) {
  cin >> n >> h;

  for(i = 0; i < n; i++)
    cin >> inters[i].ini >> inters[i].fim;

  inters[i].ini = INT_MAX;
  inters[i].fim = INT_MAX;

  maxim = 0;
  r = inters[0].fim;
  ir = 1;

  for(i = 0; i < n; i++)
  {
    l = inters[i].ini;
    while (h > 0)
    {
      if(inters[ir].ini == r)
      {
        r = inters[ir].fim;
        ir++;
      } else {
        ll aux = r;
        r = inters[ir].ini - 1;
        h -= (r-aux);
        if(h < 0)
        {
          r += h;
          h = 0;
        } else {
          r++;
          h--;
        }
      }
    }
    /* Aqui h é 0 */
    if(r-l > maxim) maxim = r-l;
    //printf("l = %lld r = %lld h = %lld ir = %lld max = %lld \n", l, r, h, ir, maxim);
    h += (inters[i+1].ini - inters[i].fim);
  }

  printf("%lld\n", maxim);

  return 0;
}
