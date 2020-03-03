#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
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
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

string t;
string b;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  b = "";
  fora (i, t.size())
    if (t[i] != 'a')
      b += t[i];
  if (b.size() % 2 == 1) { cout1e(":("); return 0; }
  // cout1e("1");

  // cout2e("t", t);
  // cout2e("b", b);

  fora (i, b.size()/2) {
    // cout2e(b[i], b[i+b.size()/2]);
    if (b[i] != b[i+b.size()/2])
      { cout1e(":("); return 0; }
  }
  // cout1e("2");


  for (int i = t.size()-1; i > t.size()-1-b.size()/2; i--) {
    // cout1e(t[i]);
    if (t[i] == 'a') { cout1e(":("); return 0; }
  }
  // cout1e("3");

  for (int i = 0; i < t.size() - (b.size()/2); i++)
    cout << t[i];
  cout << endl;

  return 0;
}
