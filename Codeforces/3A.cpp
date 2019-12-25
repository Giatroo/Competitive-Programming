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

string ss, st;
ll board[10][10];
ll movs[10][10];
pll s, t;
pll mov[8];
stack<ll> seq;

void bfs(pll v) {
  queue<pll> f;
  fora(i, 10) fora(j, 10) board[i][j] = -1;
  board[v.f][v.s] = 0;
  movs[v.f][v.s] = -1;
  f.push(v);

  while (!f.empty()) {
    v = f.front(); f.pop();
    // cout << "Olhando " << v.f << " " << v.s << endl;

    fora (i, 8) {
      pll listing = mk(v.f + mov[i].f, v.s + mov[i].s);
      if (1 <= listing.f && listing.f <= 8 &&
          1 <= listing.s && listing.s <= 8) {
        if (board[listing.f][listing.s] == -1) {
          board[listing.f][listing.s] = board[v.f][v.s] + 1;
          movs[listing.f][listing.s] = i;
          f.push(listing);
        }
      }
    }
  }
}

void findPath(pll s, pll t) {
  ll mini, imini;

  while (s.f != t.f || s.s != t.s) {
    // cout << "Olhando " << s.f << " " << s.s << endl;
    mini = board[s.f][s.s];

    fora(i, 8) {
      pll listing = mk(s.f + mov[i].f, s.s + mov[i].s);
      if (1 <= listing.f && listing.f <= 8 &&
          1 <= listing.s && listing.s <= 8)
      {
        if (board[listing.f][listing.s] < mini) {
          mini = board[listing.f][listing.s];
          imini = i;
        }
      }
    }

    seq.push(imini);
    s = mk(s.f + mov[imini].f, s.s + mov[imini].s);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(ss, st);
  s.f = ss[0] - 'a' + 1;
  s.s = ss[1] - '0';
  t.f = st[0] - 'a' + 1;
  t.s = st[1] - '0';
  mov[0] = mk(0, 1);    //R
  mov[1] = mk(0, -1);  //L
  mov[2] = mk(1, 0);   //D
  mov[3] = mk(-1, 0);  //U
  mov[4] = mk(1, 1);   //RD
  mov[5] = mk(-1, 1);   //RU
  mov[6] = mk(1, -1);   //LD
  mov[7] = mk(-1, -1);  //LU

  // cout2e(s.f, s.s);
  // cout2e(t.f, t.s);
  // cout << endl;
  bfs(s);
  // forai(i, 8) {
  //   forai(j, 8) cout << board[i][j] << " ";
  //   cout << endl;
  // }

  // cout << endl;
  //
  // forai(i, 8) {
  //   forai(j, 8) cout << movs[i][j] << " ";
  //   cout << endl;
  // }
  cout << board[t.f][t.s] << endl;
  findPath(t, s);
  while (!seq.empty()) {
    switch (seq.top()) {
      case 0:
        cout1e("D");
        break;
      case 1:
        cout1e("U");
        break;
      case 2:
        cout1e("L");
        break;
      case 3:
        cout1e("R");
        break;
      case 4:
        cout1e("LD");
        break;
      case 5:
        cout1e("RD");
        break;
      case 6:
        cout1e("LU");
        break;
      case 7:
        cout1e("RU");
        break;
    }
    seq.pop();
  }

  return 0;
}
