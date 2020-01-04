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

ll l, c;
bool grid[512][512];
ll a;

ll dist[512][512];

bool isIn(ll i, ll j) {
  return 0 <= i && i <= l-1 && 0 <= j && j <= c-1;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(l, c);
  fora (i, l) fora (j, c) {
    get1(a);
    grid[i][j] = (a == 1) ? true : false;
    dist[i][j] = INF;
  }

  // cout << endl;
  // fora (i, l) {
  //   fora (j, c) cout1(grid[i][j]) << " ";
  //   cout << endl;
  // }

  dist[0][0] = 0;
  queue<pll> q;
  q.push(mk(0, 0));

  while (!q.empty()) {
    pll cur = q.front();
    q.pop();

    for (ll i = -2; i <= 2; i++) {
      for (ll j = -2; j <= 2; j++) {
        if (isIn(cur.f + i, cur.s + j) && grid[cur.f + i][cur.s + j] &&
            dist[cur.f][cur.s] + 1 < dist[cur.f + i][cur.s + j]) {
          dist[cur.f + i][cur.s + j] = dist[cur.f][cur.s] + 1;
          q.push(mk(cur.f + i, cur.s + j));
        }
      }
    }
  }

  if (dist[l-1][c-1] < INF - 112345)
    cout1e(dist[l-1][c-1]);
  else cout1e(-1);

  // cout << endl;
  // fora (i, l) {
  //   fora (j, c)
  //     if (dist[i][j] < INF - 112345)
  //       cout1(dist[i][j]) << " ";
  //     else cout1(-1) << " ";
  //   cout << endl;
  // }


  return 0;
}
