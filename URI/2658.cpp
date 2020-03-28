#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

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

const int N = 112345;

int n, q;
int a, b, f;
int st[4*N][9], lz[4*N], aux[9];
vector<int> notes;

void build(int i, int l, int r) {
  if (l == r) {
    fr (j, 9) st[i][j] = 0;
    st[i][1] = 1;
  } else {
    int m = l + (r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    fr (j, 9) st[i][j] = (st[2*i][j] + st[2*i+1][j]);
  }

  lz[i] = 0;
}

void push(int i, int l, int r) {
  if (lz[i]) {
    fr (j, 9) aux[(j+lz[i])%9] = st[i][j];
    fr (j, 9) st[i][j] = aux[j];

    if (l != r) {
      lz[2*i] += lz[i];
      lz[2*i+1] += lz[i];
    }
  }
  lz[i] = 0;
}

void update(int i, int l, int r, int ql, int qr, int x) {
  push(i, l, r);
  if (r < ql || l > qr) return;
  if (ql <= l && r <= qr) {
    lz[i] = x;
    push(i, l, r);
    return;
  }

  int m = l + (r-l)/2;
  update(2*i, l, m, ql, qr, x);
  update(2*i+1, m+1, r, ql, qr, x);
  fr (j, 9) st[i][j] = (st[2*i][j] + st[2*i+1][j]);
}

void querry(int i, int l, int r, int ql, int qr) {
  push(i, l, r);
  if (r < ql || l > qr) {
    return;
  }
  if (ql <= l && r <= qr) {
    fr (j, 9) notes[j] += st[i][j];
    return;
  }
  int m = l + (r-l)/2;
  querry(2*i, l, m, ql, qr);
  querry(2*i+1, m+1, r, ql, qr);
}

void print(int i, int l, int r) {
  push(i, l, r);

  if (l == r) {
    int v = 0;
    fr (j, 9)
      if (st[i][j] == 1) { v = j; break; }

     printf("%d\n", v);
  } else {
    int m = l + (r-l)/2;
    print(2*i, l, m);
    print(2*i+1, m+1, r);
  }
}

int main(int argc, char const *argv[]) {
  scanf("%d%d", &n, &q);
  notes.resize(10);

  int maxi;
  build(1, 1, n);

  fr (i, q) {
    scanf("%d%d", &a, &b);
    querry(1, 1, n, a+1, b+1);

    maxi = 0;
    for (int j = 8; j >= 0; j--) {
      if (notes[j] > maxi) {
        maxi = notes[j];
        f = j;
      }
      notes[j] = 0;
    }
    update(1, 1, n, a+1, b+1, f);
  }

  print(1, 1, n);


  return 0;
}
