#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int pos[112];
  int pont;
  int id;
} Pil;

bool comp(Pil p1, Pil p2)
{
  return p1.pont > p2.pont;
}

bool compID(Pil p1, Pil p2)
{
  return p1.id < p2.id;
}

int main()
{
  int G, P, S, K;
  int i, j, k;
  int aux;
  Pil pilotos[112];
  int ks[112];
  int maior;
  Pil vencedores[112];

  cin >> G >> P;
  while(G != 0 && P != 0)
  {
    for(i = 0; i < G; i++)
      for(j = 0; j < P; j++)
      {
        scanf("%d", &(pilotos[j].pos[i]));
        pilotos[j].id = (j+1);
      }

    scanf("%d", &S);

    for(i = 0; i < S; i++)
    {
      for(j = 0; j < P; j++)
        pilotos[j].pont = 0;

      scanf("%d", &K);
      for(j = 0; j < K; j++)
        scanf("%d", &(ks[j]));

      /*for(j = 0; j < K; j++)
        printf("%d ", ks[j]);
      printf("\n");*/

      for(j = 0; j < P; j++)
        for(k = 0; k < G; k++)
          if(pilotos[j].pos[k]-1 < K)
            pilotos[j].pont += ks[pilotos[j].pos[k]-1];

      /*for(j = 0; j < P; j++)
        printf("%d ", pilotos[j].pont);
      printf("\n");*/

      sort(pilotos, pilotos+P, comp);

      /*for(j = 0; j < P; j++)
        printf("%d ", pilotos[j].pont);
      printf("\n");*/

      maior = pilotos[0].pont;

      j = 0;
      while(pilotos[j].pont == maior){
        vencedores[j] = pilotos[j];
        j++;
      }

      sort(vencedores, vencedores+j, compID);
      k = j;
      /*printf("out: ");*/
      for(j = 0; j < k-1; j++)
        printf("%d ", vencedores[j].id);
      printf("%d\n", vencedores[j].id);

    }

    cin >> G >> P;
  }

  return 0;
}
