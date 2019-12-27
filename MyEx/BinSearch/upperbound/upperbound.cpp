#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll a[1123456];
ll n;
ll x;

#define MAX 1000000000
#define MAXN 1000000

ll upperBinSearch(ll l, ll r) {
  ll m;
  ll ans = -1;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (a[m] <= x) {
      ans = m;
      l = m + 1;
    } else r = m - 1;
  }

  return ans;
}

void geraVet() {
  fora(i, n)
    a[i] = (rand() % (2*MAX)) - MAX;

  printf("Sorting...\n");
  sort(a, a+n);
}

int main(int argc, char const *argv[]) {
  FILE *arq;
  string arqNome;
  int caso;

  srand(time(NULL));
  caso = 1;


  while(caso <= 30) {
    n = rand() % MAXN;
    x = (rand() % (2*MAX)) - MAX;
    printf("Gerando vetor com %lld elementos (x = %lld)\n", n, x);
    geraVet();
    printf("Vetor gerado\n");
    arqNome = "";
    arqNome.append(to_string(caso));
    arqNome.append(".in");
    cout << "Escrevendo no arquivo..." << endl;

    arq = fopen(arqNome.c_str(), "w");
    fprintf(arq, "%lld %lld\n", n, x);
    fora(i, n-1) fprintf(arq, "%lld ", a[i]);
    fprintf(arq, "%lld\n", a[n-1]);

    fclose(arq);

    cout << arqNome << " gerado com sucesso." << endl;

    arqNome = "";
    arqNome.append(to_string(caso));
    arqNome.append(".out");
    cout << "Escrevendo no arquivo..." << endl;

    arq = fopen(arqNome.c_str(), "w");
    fprintf(arq, "%lld\n", upperBinSearch(0, n-1));

    fclose(arq);

    caso++;
  }


  /*cin >> n >> x;
  fora(i, n) cin >> a[i];*/



  return 0;
}
