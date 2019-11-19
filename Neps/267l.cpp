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

int n;
string s;
stack<char> sta;
bool ok = true;

int main(int argc, char const *argv[]) {
  cin >> n;
  fora(i, n+1)
  {
    getline(cin, s);
    fora(j, s.size())
    {
      if(s[j] == '{')
        sta.push(s[j]);
      else if(s[j] == '}')
      {
        if(sta.empty()) ok = false;
        else sta.pop();
      }

      if(!ok) break;
    }
    if(!ok) break;
  }

  if(ok && sta.empty()) cout << "S\n";
  else cout << "N\n";

  return 0;
}
