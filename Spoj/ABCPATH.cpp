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
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define inside(a, l, r) l <= a && a <= r
#define INF INT_MAX

using namespace std;

ll h, w;
char grid[112][112];
ll board[112][112];
ll maxi, num;
set<pll> as;
pll mov[8];

ll bfs(pll S) {
  queue<pll> q;
  ll curMax = 1;
  board[S.f][S.s] = 1;
  q.push(S);

  while (!q.empty()) {
    S = q.front(); q.pop();

    fora(i, 8) {
      pll listing = mk(S.f + mov[i].f, S.s + mov[i].s);
      if (inside(listing.f, 1, h) && inside(listing.s, 1, w) &&
          grid[listing.f][listing.s] == grid[S.f][S.s] + 1 &&
          board[listing.f][listing.s] == -1)
      {
          curMax = board[listing.f][listing.s] = board[S.f][S.s] + 1;
          q.push(listing);
      }
    }
  }
  return curMax;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(0, 1);
  mov[1] = mk(0, -1);
  mov[2] = mk(1, 1);
  mov[3] = mk(-1, 1);
  mov[4] = mk(1, 0);
  mov[5] = mk(-1, 0);
  mov[6] = mk(-1, -1);
  mov[7] = mk(1, -1);

  get2(h, w);
  num = 1;
  while (h*w != 0) {
    fora(i, h + 5) fora(j, w + 5) grid[i][j] = 0;
    forai(i, h) forai(j, w) {
      get1(grid[i][j]);
      if (grid[i][j] == 'A') as.insert(mk(i, j));
    }

    fora(i, h + 5) fora(j, w + 5) board[i][j] = -1;
    maxi = 0;
    forita(it, as) {
      ll aux;
      aux = bfs(*it);
      maxi = max(maxi, aux);
    }

    cout << "Case " << num++ << ": " << maxi << endl;
    // cout << endl;
    // forai(i, h) {
    //   forai(j, w) cout1(board[i][j]) << " ";
    //   cout << endl;
    // }
    as.clear();
    get2(h, w);
  }


  return 0;
}
