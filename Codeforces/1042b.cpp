#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for (auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define debug(x) #x << " = " << x << " "

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

// pd(i,s) = estou em i e já tenho s (um set de vitaminas)
// se s={a,b,c}, acabou (retorno 0)
// se chegamos em i = n e s!={a,b,c} deu errado (retornamos inf)
//
// pd(i,s) = max(tomo i, n tomo i)
// Se eu tomo i, incluo as vitaminas de i no set
// Se n tomo i, só vou pro próximo

// A questão é, como representar esse set de quem já pegamos?
// Poderíamos fazer uma pd (i, A, B, C) em que A, B, C são true ou false
// Mas o problema disso é que se tivéssemos mais vitaminas, teríamos
// MUITOS estados
//
// Dai surgem as bitmasks! (yey)
// Vamos representar então o conjunto usando um número que, quando passado
// para binário, representa um conjunto.
// Por exemplo, 101 representa {A,C}. Assim, conseguímos fazer uma dp com só
// dois parâmetros, o i e uma bitmask.
//
// Além disso, bitmasks são perfeitas, pois conseguimos fazer união,
// intersecção e tudo mais com os operadores lógicos.
//
// A união B é A | B
// A intersecção B é A & B
// 0 é o conjunto vazio
// 2^3-1 é o conjunto inteiro (pois é 111) (2^3-1 é (1<<3)-1)
// Para saber se um elemento está no conjunto, fazemos (S & (1<<i)!=0),
//  onde i é o elemento que queremos saber

const int N = 1123;
int n;
int p[N];
int A[N];
int memo[N][10];

bool in(char a, string s) {
	fr(i, s.size()) if (s[i] == a) return true;
	return false;
}

int dp(int i, int mask) {
	if (mask == 7) return 0;
	if (i == n) return INF;

	int pdm = memo[i][mask];
	if (pdm != -1) return pdm;

	pdm = min(dp(i + 1, mask), dp(i + 1, mask | A[i]) + p[i]);

	memo[i][mask] = pdm;
	return pdm;
}

int main(int argc, char const *argv[]) {
	fastio;

	cin >> n;
  fr (i, n+3) fr (j, 10) memo[i][j] = -1;
	fr(i, n) {
		cin >> p[i];
		string s;
		cin >> s;

		if (in('A', s)) A[i] |= (1 << 2);
		if (in('B', s)) A[i] |= (1 << 1);
		if (in('C', s)) A[i] |= (1 << 0);
	}

	int x = dp(0, 0);
	if (x >= INF)
		cout << -1 << endl;
	else
		cout << x << endl;

	return 0;
}
