#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
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

ll n, m, k;
char maze[512][512];
pair<ll, ll> caller[512][512];
char checked[512][512];
pair<ll, ll> mov[8];
pair<ll, ll> fri;

void draw(pair<ll, ll> v) {
  queue<pair<ll, ll>> st;
  st.push(v);
  caller[v.f][v.s] = v;
  forai (i, n) forai (j, m) checked[i][j] = -1;
  checked[v.f][v.s] = 1;

  while (!st.empty()) {
    v = st.front();
    st.pop();

    bool leaf = true;
    fora(i, 4) {
      pair<ll, ll> listing = mk(v.f + mov[i].f, v.s + mov[i].s);

      if (checked[listing.f][listing.s] == -1 && maze[listing.f][listing.s] == '.')
      {
        checked[listing.f][listing.s] = 1;
        st.push(listing);
        caller[listing.f][listing.s] = v;
        leaf = false;

        // cout << "Processando " << listing.f << " " << listing.s << endl;
      }
    }

    if (leaf && k > 0) {
      maze[v.f][v.s] = 'X';
      if (caller[v.f][v.s].f != v.f &&
          caller[v.f][v.s].s != v.s &&
         maze[caller[v.f][v.s].f][caller[v.f][v.s].s] == '.')
        st.push(caller[v.f][v.s]);
      k--;
    }
  }
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get3(n, m, k);
  fora (i, n + 2) fora (j, m + 2) { maze[i][j] = '#'; }
  forai (i, n) forai (j, m) get1(maze[i][j]);
  mov[0] = mk(0, 1);
  mov[1] = mk(0, -1);
  mov[2] = mk(1, 0);
  mov[3] = mk(-1, 0);

  while (k > 0) {
    // cout << "Entrou\n";
    bool find = false;
    ll i, j;

    for(i = 1; i <= n && !find; i++) {
      for(j = 1; j <= m && !find; j++) {
        if (maze[i][j] == '.') {
          /*int leaf = 0;
          fora(a, 4 && leaf < 2) {
            fri = mk(i + mov[a].f, j + mov[a].s);
            if (maze[fri.f][fri.s] == '.') leaf++;
          }
          if (leaf >= 2)*/
          find = true;
        }
      }
    }

    // cout << "Entrando com " << i - 1 << " " << j - 1 << endl;
    draw(mk(--i, --j));
  }


  forai (x, n) {
    forai(y, m) cout1(maze[x][y]);
    cout << endl;
  }

  return 0;
}
