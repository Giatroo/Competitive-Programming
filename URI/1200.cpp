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
#define get4(a, b, c, d) cin >> (a) >> (b) >> (c) >> (d)
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define M 1000000007

using namespace std;

typedef struct no {
    char v;
    struct no * l;
    struct no * r;
} Node;

typedef Node * Tree;

Tree t;

void insert(char v) {
  Tree newT, cur, prev;
  newT = (Tree) malloc(sizeof *newT);
  newT->v = v;
  newT->l = newT->r = NULL;

  if (t == NULL) { t = newT; return; }

  cur = prev = t;
  while (cur != NULL) {
    prev = cur;
    cur = (v < cur->v) ? cur->l : cur->r;
  }

  if (v < prev->v) prev->l = newT;
  else prev->r = newT;
}

bool exists(char v) {
  Tree cur, prev;

  if (t == NULL) return false;

  cur = prev = t;
  while (cur != NULL) {
    prev = cur;
    if (v == cur->v) return true;
    cur = (v < cur->v) ? cur->l : cur->r;
  }

  return false;
}

vector<char> path;

void pre(Tree tr) {
  if (tr != NULL) {
    path.pb(tr->v);
    pre(tr->l);
    pre(tr->r);
  }
}

void in(Tree tr) {
  if (tr != NULL) {
    in(tr->l);
    path.pb(tr->v);
    in(tr->r);
  }
}

void post(Tree tr) {
  if (tr != NULL) {
    post(tr->l);
    post(tr->r);
    path.pb(tr->v);
  }
}

void printpath() {
  fora (i, path.size()) {
    cout << path[i];
    if (i != path.size() - 1) cout << " ";
  }
  cout << endl;
  path.clear();
}

string s;
char c;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> s) {
    if (s.size() == 1) {
      cin >> c;
      if (s[0] == 'I') insert(c);
      else
        cout << c << (exists(c) ? " existe" : " nao existe") << endl;
    } else {
      switch (s[1]) {
        case 'N':
          in(t);
        break;
        case 'R':
          pre(t);
        break;
        case 'O':
          post(t);
        break;
      }
      printpath();
    }
  }

  return 0;
}
