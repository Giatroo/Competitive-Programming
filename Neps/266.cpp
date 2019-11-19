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

string s;
bool div2, div3, div5;
ll sum;

int main(int argc, char const *argv[]) {
  cin >> s;
  div2 = div3 = div5 = false;
  div2 = ((s[s.size()-1] - '0') % 2 == 0);
  div5 = ((s[s.size()-1] - '0') % 5 == 0);

  sum = 0;
  fora(i, s.size())
      sum += s[i] - '0';
  div3 = (sum % 3 == 0);

  if(div2) cout << "S\n";
  else cout << "N\n";
  if(div3) cout << "S\n";
  else cout << "N\n";
  if(div5) cout << "S\n";
  else cout << "N\n";

  return 0;
}
