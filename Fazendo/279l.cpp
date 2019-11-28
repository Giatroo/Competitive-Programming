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
#define forita(c) for(auto it = c.begin(); it != c.end(); it++)
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


ll t, m, n;
string lin1, lin2;
string palavras[10000];
map<string, string> dic;

//retorna o número de palavras + 1
int pegaPalavras(string linha) {
  int i = 0;
  int j = 0;
  string palavra;

  while(linha[j] != '\0') {
    palavra.clear();
    while(linha[j] != ' ' && linha[j] != '\0') {
      palavra += linha[j];
      j++;
    }
    j++;
    palavras[i++] = palavra;
  }
  return i;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;

  fora(a, t) {
    cin >> m >> n;
    getline(cin, lin1);

    fora(i, m) {
      getline(cin, lin1);
      getline(cin, lin2);
      dic[lin1] = lin2;
    }

    fora(i, n) {
      getline(cin, lin1);
      ll k = pegaPalavras(lin1);

      fora(j, k) {
        if (dic.find(palavras[j]) == dic.end())
          cout << palavras[j] << " ";
        else
          cout << dic[palavras[j]] << " ";
      }
      cout << endl;
    }

    if(a != t-1)
    cout << endl;
  }


  return 0;
}
