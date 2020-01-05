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

ll h, l;
set<ll> cores;
ll color[212][212];
ll vizi[212][212];
vector<pair<ll, ll>> zeros;
ll menorArea, curArea;
pair<ll, ll> mov[4];

ll bfs(pair<ll, ll> fonte) {
  ll area = 0;
  queue<pair<ll, ll>> fila;
  fila.push(fonte);
  vizi[fonte.f][fonte.s] = 1;

  // cout << "Cor " << color[fonte.f][fonte.s] << ": ";

  while (!fila.empty()) {
    fonte = fila.front();
    fila.pop();
    area++;

    fora(i, 4) {
      if (color[fonte.f + mov[i].f][fonte.s + mov[i].s] ==
          color[fonte.f][fonte.s] &&
          vizi[fonte.f + mov[i].f][fonte.s + mov[i].s] == -1)
      {
        vizi[fonte.f + mov[i].f][fonte.s + mov[i].s] = 1;
        fila.push(mk(fonte.f + mov[i].f, fonte.s + mov[i].s));
      }
    }
  }

  // cout << area << endl;

  return area;
}

void desvizita(pair<ll, ll> fonte) {
  queue<pair<ll, ll>> fila;
  fila.push(fonte);
  vizi[fonte.f][fonte.s] = -1;

  while (!fila.empty()) {
    fonte = fila.front();
    fila.pop();

    fora(i, 4) {
      if (color[fonte.f + mov[i].f][fonte.s + mov[i].s] ==
          color[fonte.f][fonte.s] &&
          vizi[fonte.f + mov[i].f][fonte.s + mov[i].s] != -1)
      {
        vizi[fonte.f + mov[i].f][fonte.s + mov[i].s] = -1;
        fila.push(mk(fonte.f + mov[i].f, fonte.s + mov[i].s));
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(h, l);
  mov[0] = mk(0, 1);
  mov[1] = mk(0,-1);
  mov[2] = mk(1, 0);
  mov[3] = mk(-1, 0);
  menorArea = INT_MAX;
  fora (i, h+2)
    fora (j, l+2)
      color[i][j] = vizi[i][j] = -1;

  forai (i, h) forai (j, l) {
    get1(color[i][j]);
    if (color[i][j] == 0) zeros.pb(mk(i, j));
    else cores.insert(color[i][j]);
  }

  forai (i, h) forai (j, l) {
    if (vizi[i][j] == -1) {
      curArea = bfs(mk(i, j));
      if (curArea < menorArea) menorArea = curArea;
    }
  }

  // cout << "Area min (0): " << menorArea << endl;

  forita (cor, cores){
    forita (it, zeros) {
      color[it->f][it->s] = *cor;
      desvizita(mk(it->f, it->s));
    }

    forita (it, zeros) {
      if (vizi[it->f][it->s] == -1) {
        curArea = bfs(mk(it->f, it->s));
        if (curArea < menorArea) menorArea = curArea;
      }
    }

    // cout << "Area min (" << *cor << "): " << menorArea << endl;
  }

  cout1e(menorArea);

  return 0;
}
