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

char maze[512][512];
bool listed[512][512];
ll m, n, k, s;
pair<ll, ll> mov[5];

void floodfill(pair<ll, ll> v) {
  queue<pair<ll, ll>> q;
  ll visited = 0;
  forai(i, n) forai(j, m) listed[i][j] = false;
  listed[v.f][v.s] = true;
  q.push(v);

  while (!q.empty()) {
    v = q.front(); q.pop();
    visited++;
    if (s - visited < k)
      maze[v.f][v.s] = 'X';

    forai(i, 4) {
      pair<ll, ll> l = mk(v.f + mov[i].f, v.s + mov[i].s);
      if (!listed[l.f][l.s] && maze[l.f][l.s] == '.')
      {
        listed[l.f][l.s] = true;
        q.push(l);
      }
    }
  }

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(0, 0);
  mov[1] = mk(0, 1);
  mov[2] = mk(0, -1);
  mov[3] = mk(1, 0);
  mov[4] = mk(-1, 0);
  get3(n, m, k);
  s = 0;

  fora(i, n + 2) fora(j, m + 2) maze[i][j] = '#';
  forai(i, n) forai(j, m)  {
    get1(maze[i][j]);
    if (maze[i][j] == '.') s++;
  }

  bool encontrou = false;
  ll x, y;
  for (x = 1; x <= n && !encontrou; x++)
    for (y = 1; y <= m && !encontrou; y++)
      encontrou = (maze[x][y] == '.');
  floodfill(mk(--x, --y));
  forai(i, n) {
    forai(j, m) cout1(maze[i][j]);
    cout << endl;
  }


  return 0;
}
