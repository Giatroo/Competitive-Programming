#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n, d;
ll k;
string s, nova;
stack<int> pilha;

int main(int argc, char const *argv[]) {
  cin >> n >> d;
  while(n*d != 0)
  {
    cin >> s;
    k = 0;
    nova = "";

    fora(i, n)
    {
      // if(pilha.empty()) cout << "Pilha vazia\n";
      // else cout << "Topo = " << pilha.top() << endl;
      if(k != d && !pilha.empty() && pilha.top() < s[i] - '0') {
        // cout << "Desempilhando " << pilha.top() << endl;
        pilha.pop();
        k++;
        i--;
      } else {
        pilha.push(s[i] - '0');
        // cout << "Empilhando " << s[i]-'0' << endl;
      }
    }

    while(k != d)
    {
      // cout << "Desempilhando " << pilha.top() << endl;
      pilha.pop();
      k++;
    }

    // cout << "Criando string\n";
    while(!pilha.empty()){
      // cout << "Topo é " << pilha.top() << endl;
      nova += pilha.top() + '0';
      pilha.pop();
    }

    reverse(nova.begin(), nova.end());

    cout << nova << endl;

    cin >> n >> d;
  }
  return 0;
}
