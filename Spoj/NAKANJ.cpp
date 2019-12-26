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
#define INF INT_MAX

using namespace std;

bool isInside(pll p) {
  return 1 <= p.f && p.f <= 8 && 1 <= p.s && p.s <= 8;
}

pll CoordToPll(string s) {
  pll ret;
  ret.f = s[0] - 'a' + 1;
  ret.s = s[1] - '0';
  return ret;
}

pll mov[8];
ll t;
pll s, e;
string aux;
ll board[10][10];

void bfs(pll S) {
  queue<pll> f;
  fora(i, 10) fora(j, 10) board[i][j] = -1;
  board[S.f][S.s] = 0;
  f.push(S);

  while (!f.empty()) {
    S = f.front(); f.pop();

    fora(i, 8) {
      pll listing = mk(S.f + mov[i].f, S.s + mov[i].s);
      if (isInside(listing) && board[listing.f][listing.s] == -1) {
        board[listing.f][listing.s] = board[S.f][S.s] + 1;
        f.push(listing);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  mov[0] = mk(1, 2);
  mov[1] = mk(2, 1);
  mov[2] = mk(2, -1);
  mov[3] = mk(1, -2);
  mov[4] = mk(-1, -2);
  mov[5] = mk(-2, -1);
  mov[6] = mk(-2, 1);
  mov[7] = mk(-1, 2);

  get1(t);
  fora(i, t) {
    get1(aux);
    s = CoordToPll(aux);
    get1(aux);
    e = CoordToPll(aux);
    bfs(s);

    // forai(j, 8) {
    //   forai(k, 8) cout1(board[j][k]) << " ";
    //   cout1e("");
    // }

    cout1e(board[e.f][e.s]);
  }


  return 0;
}
