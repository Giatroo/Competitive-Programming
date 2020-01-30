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
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

ll n, m;
ll x, y;
bool adj[512][512];
string s;
bool temA, temC;
bool ehString;
char curC;

bool isB(ll v) {
  bool yes = true;
  forai(i, n && yes) if (i != v) yes = adj[v][i];
  return yes;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, m);
  s = "";
  fora(i, n) s.append("x");
  fora(i, n + 2) fora(j, n + 2) adj[i][j] = false;

  fora(i, m) {
    get2(x, y);
    adj[x][y] = adj[y][x] = true;
  }

  ehString = true;
  curC = 'a';

  forai(i, n && ehString)
    if (isB(i)) { s[i-1] = 'b'; continue; }

  forai(i, n && ehString) {
    if (s[i-1] == 'x') {
      if (curC == 'e') { ehString = false; continue; }
      if (curC == 'a') {
        s[i-1] = curC;
        forai (j, n)
          if (adj[i][j] && s[j-1] == 'x')
            s[j-1] = curC;
      } else if (curC == 'c') {
        s[i-1] = curC;
        forai (j, n) if (adj[i][j]) {
          if (s[j-1] == 'a') { ehString = false; continue; }
          if (s[j-1] == 'x')
            s[j-1] = curC;
        }
      }
      curC += 2;
    }
  }

  forai(i, n && ehString) {
    if (s[i-1] == 'a' || s[i-1] == 'c') {
      forai(j, n && ehString) {
        if (s[j-1] == 'b' || i == j) continue;
        if ((s[j-1] == s[i-1] && !adj[i][j]) ||
            (s[j-1] != s[i-1] && adj[i][j]))
          ehString = false;
      }
    }
  }


  if (ehString)
    cout << "Yes" << endl << s << endl;
  else cout << "No" << endl;


  return 0;
}
