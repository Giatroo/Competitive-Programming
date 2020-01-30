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

typedef struct node {
  ll v;
  struct node *l;
  struct node *r;
} Node;

ll t, n, a;
Node *tree;

void insert(ll val) {
  Node *newN, *cur, *prev;
  newN = (Node*)malloc(sizeof *newN);
  newN->v = val;
  newN->l = newN->r = NULL;

  if (tree == NULL) { tree = newN; return; }

  cur = tree;
  prev = NULL;
  while (cur != NULL) {
    prev = cur;
    cur = (cur->v > val) ? cur->l : cur->r;
  }
  if (prev->v > val) prev->l = newN;
  else prev->r = newN;
}

vector<ll> path;

void BFS() {
  queue<Node *> q;
  Node *cur;
  q.push(tree);

  while (!q.empty()) {
    cur = q.front(); q.pop();
    if (cur == NULL) continue;
    path.pb(cur->v);
    q.push(cur->l);
    q.push(cur->r);
  }
}

void printpath() {
  fora (i, path.size()) {
    cout << path[i];
    if (i != path.size()-1) cout << " ";
  }
  cout << endl;
  path.clear();
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(t);
  fora (k, t) {
    get1(n);
    tree = NULL;
    fora (i, n) {
      get1(a);
      insert(a);
    }

    cout << "Case " << k+1 << ":" << endl;
    BFS();
    printpath();
    cout << endl;
  }

  return 0;
}
