#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef struct {
  ll l; ll r;
} Intervalo;

ll N;
ll t;
ll tot;
Intervalo inters[11234];

bool comp(Intervalo i1, Intervalo i2)
{
  return i1.r < i2.r;
}

int main(int argc, char const *argv[]) {
  scanf("%lld", &N);

  for(ll i = 0; i < N; i++)
    scanf("%lld %lld", &(inters[i].l), &(inters[i].r));

  tot = t = 0;
  sort(inters, inters+N, comp);

  for(ll i = 0; i < N; i++){
    if(inters[i].l < t) continue;

    tot++;
    t = inters[i].r;
  }

  printf("%lld\n", tot);

  return 0;
}
