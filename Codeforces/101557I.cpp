#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frd(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define cout1e(a) cout << (a) << endl
#define cout2e(a, b) cout << (a) << " " << (b) << endl
#define cout3e(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define cout4e(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl
#define debug(x) cout << #x << " = " << x << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

string key, s;
char t[5][5];
map<char, pii> m;
string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ans;

int main(int argc, char const *argv[]) { fastio;
  getline(cin, key);
  getline(cin, s);
  ans = "";
  int index = 0;
  fr (i, key.size()) {
    if (key[i] == ' ') continue;
    if (s1[key[i]-'a'] != 1) {
      t[index / 5][index % 5] = key[i]-'a'+'A';
      m[key[i]-'a'+'A'] = mk(index/5, index%5);
      s1[key[i]-'a'] = 1;
      index++;
    }
  }
  int l = 0;
  while (index != 26) {
    while (s1[l] == 1 || s1[l] == 'Q') l++;
    t[index / 5][index % 5] = s1[l];
    m[s1[l]] = mk(index/5, index%5);
    index++; l++;
  }

  //fr (i, 5) {
  //   fr (j, 5) cout << t[i][j] << " ";
  //   cout << endl;
  //}
  
  char c1, c2;
  pii p1, p2;
  for (l = 0; l < s.size();) {
    while (s[l] == ' ') l++;
    if (l >= s.size()) break;
    c1 = s[l++];
    while (s[l] == ' ') l++;
    if (l >= s.size()) c2 = 'X';
    else c2 = s[l++];
    if (c1 == c2) { c2 = 'X'; l--; }

    p1 = m[c1-'a'+'A'];
    if (c2 != 'X')
      p2 = m[c2-'a'+'A'];
    else p2 = m[c2];

    if (p1.f == p2.f) {
      ans += t[p1.f][(p1.s+1)%5];
      ans += t[p2.f][(p2.s+1)%5];
    } else if (p1.s == p2.s) {
      ans += t[(p1.f+1)%5][p1.s];
      ans += t[(p2.f+1)%5][p2.s];
    } else { 
      ans += t[p1.f][p2.s];
      ans += t[p2.f][p1.s];
    }
  }
  cout1e(ans);

  return 0;
}
