#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> a[212345];

ll verificaPara(ll h, ll n){ //n é o tamanho do array
  ll max;
  ll l, r;
  ll il, ir;

  il = ir = max = 0;
  l = a[il].first;
  r = a[ir].first;

  printf("n = %lld\n", n);

  while(r < n && l <= r){
    printf("l = %lld r = %lld h = %lld max = %lld\n", l, r, h, max);
    if(h >= 0){
      if(h - (a[ir].second - a[ir].first) < 0){
        r += h;
        h = -1;
      } else {
        h -= (a[ir].second - a[ir].first);
        ir++;
        r = a[ir].first;
      }
    } else {
      if(l < a[il].second){
        l++;
        h = 1;
      } else {
        il++;
        l = a[il].first;
      }
    }
    if(max < r - l) max = r - l;
  }

  printf("l = %lld r = %lld h = %lld max = %lld\n", l, r, h, max);

  return max;
}

int main()
{
  ll i, j;
  ll n, h;
  ll p, s;
  scanf("%lld %lld", &n, &h);

  p = s = 0;

  for(i = 0; i < n; i++){
    scanf("%lld", &p);
    a[i].first = s;
    a[i].second = p;

    scanf("%lld", &s);
  }
  a[i].first = s;
  a[i].second = 212345; //+inf

  printf("%lld\n", verificaPara(h, a[i].first+h));


  return 0;
}
