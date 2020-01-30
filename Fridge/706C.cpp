#include <bits/stdc++.h>
typedef long long int ll;
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
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

ll n;
ll c[112345];
string s[112345];
ll dp[112345];

void reverse(string &s) {
  ll b = 0, e = s.size()-1;
  while (b != e && b != e+1)
    swap(s[b++], s[e--]);
}

string getReversed(string s) {
  string s1 = s;
  ll b = 0, e = s1.size()-1;
  while (b != e && b != e+1)
    swap(s1[b++], s1[e--]);
  return s1;
}

ll f(ll i) {
  ll rever, notrever;

  if (i == n + 1) return 0;
  else if (dp[i] != -1) return dp[i];

  rever = notrever = -1;

  reverse(s[i]);
  if (s[i].compare(s[i-1]) > 0)
  {
    ll aux = f(i+1);
    if (aux != -1)
      rever = c[i] + aux;
  }
  reverse(s[i]);

  if (s[i].compare(s[i-1]) > 0) {
    ll aux = f(i+1);
    if (aux != -1)
      notrever = aux;
  }

  if (notrever != -1) return dp[i] = notrever;
  else return dp[i] = rever;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a = "ab";
  cout1e(a.compare("\0"));

/*  get1(n);
  forai(i, n) get1(c[i]);
  s[0] = "\0";
  forai(i, n) get1(s[i]);

  dp[0] = 0;
  cout1e(f(1));
  fora(i, n+1) cout1(dp[i]) << " ";
  cout << endl;*/

  return 0;
}
