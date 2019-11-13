#include <bits/stdc++.h>

using namespace std;

typedef struct{
  int a;
  int b;
} Visto;

int t;
int a, b, c;
int i;

Visto vistos[4123456];
int tot_vistos;

int gcd(int a, int b)
{
  if(a % b == 0) return b;
  return gcd(a%b,a);
}

bool jaVisto(Visto v)
{
  for(int i = 0; i < tot_vistos; i++)
    if(vistos[i].a == v.a && vistos[i].b == v.b) return true;
  return false;
}

int decide(Visto v, int altura)
{
  printf("v.a = %d v.b = %d h = %d\n", v.a, v.b, altura);

  if(jaVisto(v)) return INT_MAX;
  if(v.a == c || v.b == c) return altura;

  int c1, c2, c3, c4;
  Visto vl;

  vistos[tot_vistos++] = v;

  vl.a = 0;
  vl.b = b;
  c1 = decide(vl, altura+1);

  vl.a = a;
  vl.b = 0;
  c2 = decide(vl, altura+1);

  vl.a = v.b;
  vl.b = 0;
  if(vl.a > a)
  {
    vl.b = vl.a - a;
    vl.a = a;
  }
  c3 = decide(vl, altura+1);


  vl.a = 0;
  vl.b = v.a;
  if(vl.b > b)
  {
    vl.a = vl.b - b;
    vl.b = b;
  }
  c4 = decide(vl, altura+1);

  tot_vistos = 0;
  return min(min(c1, c2), min(c3, c4));
}

int main(int argc, char const *argv[]) {
  scanf("%d", &t);

  for(i = 0; i < t; i++)
  {
    tot_vistos = 0;
    scanf("%d %d %d", &a, &b, &c);
    if(gcd(a, b) != 1 || (c > a && c > b))
      printf("%d\n", -1);
    else{
      Visto v;
      v.a = 0;
      v.b = 0;
      printf("%d\n", decide(v, 0));
    }
  }


  return 0;
}
