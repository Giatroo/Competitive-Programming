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

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll m, n;
ll t;
char aux1[80], aux2[80], aux3[80];
map<string, string> dic;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;

  fora(a, t) {
    cin >> m >> n;

    fora(i, m) {
      scanf(" %s", aux1);
      aux2[0] = '\0';
      aux3 = NULL;
      while(aux3[0] != '\0')
      {
        scanf(" %s", aux3);
        printf("Lido = '%s'\n", aux3);
        strcat(aux2, aux3);
      }


      // cout << "Leitura 1: '" << aux1 << "'" << endl;
      // cout << "Leitura 2: '" << aux2 << "'" << endl;

      dic[aux1] = aux2;
    }

    /*fora(i, n) {
      ll j = 0;
      getline(cin, aux1);

     cout << "aux1 = '" << aux1 << "'" << endl;

volta:
      aux2 = "";
      while(aux1[j] != ' ' && aux1[j] != '\n' && aux1[j] != '\0')
        aux2 += aux1[j++];
      j++;

      // cout << "aux2 = '" << aux2 << "'" << endl;
      if(aux2.compare("") == 0) continue;

      if(dic.find(aux2) == dic.end())
        cout << aux2 << " ";
      else
        cout << dic[aux2] << " ";

      if(aux2.compare("") != 0) goto volta;
    }
    // cout << "\nFim";
    cout << endl << endl;*/


  }

  return 0;
}
