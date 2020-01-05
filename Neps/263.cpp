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

string s;
bool d4, d9, d25;

void print(bool a) {
  if (a) cout1e("S");
  else cout1e("N");
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(s);
  if (s.size() == 1) {
    d4 = (s[0] - '0') % 4 == 0;
    d25 = (s[0] - '0') % 25 == 0;
  } else {
    d4 = ((s[s.size()-1] - '0' + 10*(s[s.size()-2] - '0')) % 4 == 0);
    d25 = (((s[s.size()-1] - '0') + (10*(s[s.size()-2] - '0'))) % 25 == 0);
  }

  ll sum = 0;
  fora(i, s.size()) {
    sum += s[i] - '0';
    sum %= 9;
  }
  d9 = (sum == 0);

  print(d4);
  print(d9);
  print(d25);

  return 0;
}
