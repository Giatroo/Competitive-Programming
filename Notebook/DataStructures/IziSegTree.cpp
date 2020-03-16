#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

const int N = 1e5;
int n;
int t[2*N];

void build() {
  for (int i = n - 1; i >= 1; i--) // para todo nó interno:
    t[i] = t[i<<1] + t[i<<1|1];
  // t[i] = t[2*i] + t[2*i+1];
}

void update(int p, int v) {
  // atualiza a[p] com v
  // sabemos que t[p+n] é o equivalente a "a[p]",
  // logo t[p+n] = v é atualizar a raiz
  // Daí, vamos dividindo p por 2 até chegar na raiz

  for (t[p += n] = v; p > 1; p >>= 1)
    t[p>>1] = t[p] + t[p^1];
    // "t[p/2] = t[p] + t[p+1]"
}

// soma de [l,r)
int query(int l, int r) {
  int ans = 0; // começamos a resposta de 0
  // começamos l de onde estaria a raiz representando [l,l]
  // começamos r de onde estaria a raiz representando [r,r]
  // enquanto l < r
  // dividimos l e r (fazemos eles irem para seu pai)

  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    // Se l é ímpar, então ele é filho direito de l/2
    // e, logo, precisamos adicioná-lo à resposta e
    // fazer l ir para a direita (fazendo l++)
    // depois vamos dividir l por 2 e fazer a mesma coisa

    // O mesmo se aplica a r, mas ao contrário
    // (quando ele é impar, precisamos pegar
    // a parte da esquerda, por isso decrementamos antes)

    // Para visualizar melhor, olhe a img:
    // http://i.imgur.com/GGBmcEP.png
    // e tente simular onde l e r estão em cada iteração

    if (l&1) ans += t[l++];
    if (r&1) ans += t[--r];
  }

  return ans;
}

void showSeg() {
  for (int i = 0; i < 2*n; i++) {
    cout2e(i, t[i]);
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", t+n+i);
  build();
  showSeg();
  cout << query(0, 4) << endl;

  return 0;
}
