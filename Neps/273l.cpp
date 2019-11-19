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


ll T;
string s;
stack<char> pilha;
bool ok;

int main(int argc, char const *argv[]) {
  cin >> T;

  fora(i, T)
  {
    cin >> s;
    ok = true;
    fora(j, s.size())
    {
      if(!ok) break;
      if(s[j] == '{' || s[j] == '(' || s[j] == '[')
        pilha.push(s[j]);
      else {
        if(pilha.empty()) {
          ok = false;
          break;
        }
        switch (s[j]) {
          case '}':
            ok = pilha.top() == '{';
            break;
          case ']':
            ok = pilha.top() == '[';
            break;
          case ')':
            ok = pilha.top() == '(';
            break;
        }
        pilha.pop();
      }
    }

    if(ok && pilha.empty()) cout << "S\n";
    else cout << "N\n";
    while(!pilha.empty()) pilha.pop();
  }

  return 0;
}
