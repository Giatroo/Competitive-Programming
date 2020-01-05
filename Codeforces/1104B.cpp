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

string s;
ll i = 1, t = 0;
stack<char> st;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  st.push(s[0]); // 1 <= |s|

  while (s[i] != '\0') {
    if (!st.empty() && s[i] == st.top()) {
      st.pop();
      t += 1;
      t %= 2;
    } else {
      st.push(s[i]);
    }
    i++;
  }

  if(t == 0) cout << "No\n";
  else cout << "Yes\n";

  return 0;
}
