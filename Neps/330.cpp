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

const ll N = 112345;

#define esq f.f
#define dir f.s
#define val s

typedef struct no {
  pair<pll, ll> ma;
  pair<pll, ll> pre;
  pair<pll, ll> suf;
  ll tot;
} Node;

ll n, t;
ll q, a, b;
ll arr[N];
ll neg, cur, maxi;

Node st[4*N];

bool cmp(pair<pll, ll> a, pair<pll, ll> b) {
  if (a.val > b.val) return true;
  else if (b.val > a.val) return false;
  else return (a.dir-a.esq > b.dir-b.esq);

}

void build(ll i, ll l, ll r) {
  if (l == r) {
    if (arr[l] >= 0) {
      // Sufixo, prefixo e máximo são o a[l]
      st[i].ma = mk(mk(l, r), arr[l]);
      st[i].pre = mk(mk(l, r), arr[l]);
      st[i].suf = mk(mk(l, r), arr[l]);
    } else {
      // O máximo é o a[l] (negativo mesmo)
      st[i].ma = mk(mk(l, r), arr[l]);
      // Pref e Suf são nulos
      st[i].pre = mk(mk(-1, -1), 0);
      st[i].suf = mk(mk(-1, -1), 0);
      // [-1, -1] será a convensão de nulo
    }
    st[i].tot = arr[l];
  } else {
    ll m = l + (r-l)/2;

    build(2*i, l, m);
    build(2*i+1, m+1, r);

    pair<pll, ll> vet[3];
    vet[0] = mk(mk(st[2*i].ma.esq, st[2*i].ma.dir), st[2*i].ma.val);
    vet[1] = mk(mk(st[2*i+1].ma.esq, st[2*i+1].ma.dir), st[2*i+1].ma.val);

    if (st[2*i].suf.esq == -1 && st[2*i+1].pre.dir == -1) {
      vet[2] = mk(mk(-1, -1), -LINF);
    } else if (st[2*i].suf.esq == -1) {
      vet[2] = mk(mk(st[2*i+1].pre.esq, st[2*i+1].pre.dir), st[2*i+1].pre.val);
    } else if (st[2*i+1].pre.dir == -1) {
      vet[2] = mk(mk(st[2*i].suf.esq, st[2*i].suf.dir), st[2*i].suf.val);
    } else {
      vet[2] = mk(mk(st[2*i].suf.esq, st[2*i+1].pre.dir), st[2*i].suf.val+st[2*i+1].pre.val);
    }

    // fr (i, 3)
    //   cout3e(vet[i].esq, vet[i].dir, vet[i].val);

    sort(vet, vet+3, cmp);
    // cout << endl;
    // cout3e(vet[0].esq, vet[0].dir, vet[0].val);
    // cout << endl << endl << endl;

    st[i].ma = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);


    vet[0] = mk(mk(st[2*i].pre.esq, st[2*i].pre.dir), st[2*i].pre.val);
    vet[1] = mk(mk(l, st[2*i+1].pre.dir), st[2*i].tot + st[2*i+1].pre.val);
    if (vet[1].dir == -1) vet[1].dir = m;

    sort(vet, vet+2, cmp);

    st[i].pre = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);


    vet[0] = mk(mk(st[2*i+1].suf.esq, st[2*i+1].suf.dir), st[2*i+1].suf.val);
    vet[1] = mk(mk(st[2*i].suf.esq, r), st[2*i+1].tot + st[2*i].suf.val);
    if (vet[1].esq == -1) vet[1].esq = m+1;

    sort(vet, vet+2, cmp);

    st[i].suf = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);

    st[i].tot = st[2*i].tot + st[2*i+1].tot;
  }
}

Node querry(ll i, ll l, ll r, ll ql, ll qr) {
  Node ret, left, right;

  if (qr < l || r < ql) {
    ret.ma = mk(mk(-1, -1), -LINF);
    ret.suf = mk(mk(-1, -1), -LINF);
    ret.pre = mk(mk(-1, -1), -LINF);
    ret.tot = 0;
    return ret;
  }

  if (ql <= l && r <= qr) return st[i];

  ll m = l + (r-l)/2;
  left = querry(2*i, l, m, ql, qr);
  right = querry(2*i+1, m+1, r, ql, qr);

  pair<pll, ll> vet[3];
  vet[0] = mk(mk(left.ma.esq, left.ma.dir), left.ma.val);
  vet[1] = mk(mk(right.ma.esq, right.ma.dir), right.ma.val);

  if (left.suf.esq == -1 || right.pre.dir == -1) {
    vet[2] = mk(mk(-1, -1), -LINF);
  } else {
    vet[2] = mk(mk(left.suf.esq, right.pre.dir), left.suf.val + right.pre.val);
  }

  // cout << "Nó " << i << ":\n";
  // fr (i, 3)
  //   cout3e(vet[i].esq, vet[i].dir, vet[i].val);

  sort(vet, vet+3, cmp);
  // cout << endl;
  // cout3e(vet[0].esq, vet[0].dir, vet[0].val);
  // cout << endl << endl << endl;

  ret.ma = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);


  vet[0] = mk(mk(left.pre.esq, left.pre.dir), left.pre.val);
  vet[1] = mk(mk(l, right.pre.dir), left.tot + right.pre.val);
  if (vet[1].dir == -1) vet[1].dir = m;

  sort(vet, vet+2, cmp);

  ret.pre = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);


  vet[0] = mk(mk(right.suf.esq, right.suf.dir), right.suf.val);
  vet[1] = mk(mk(left.suf.esq, r), right.tot + left.suf.val);
  if (vet[1].esq == -1) vet[1].esq = m+1;

  sort(vet, vet+2, cmp);

  ret.suf = mk(mk(vet[0].esq, vet[0].dir), vet[0].val);

  ret.tot = left.tot + right.tot;

  return ret;
}


int main(int argc, char const *argv[]) {

  scanf("%lld", &t);
  fr (k, t) {
    scanf("%lld", &n);
    frr (i, n) scanf("%lld", &(arr[i]));
    build(1, 1, n);

    // cout << "Após buildar:\n";
    // frr (i, 4*n) {
    //   cout << "Nó " << i << ":\n";
    //   cout << "\t" << st[i].ma.esq << " " << st[i].ma.dir << " " << st[i].ma.val << endl;
    //   cout << "\t" << st[i].pre.esq << " " << st[i].pre.dir << " " << st[i].pre.val << endl;
    //   cout << "\t" << st[i].suf.esq << " " << st[i].suf.dir << " " << st[i].suf.val << endl;
    //   cout << "\t" << st[i].tot << endl;
    //
    // }

    scanf("%lld", &q);
    fr (i, q) {
      scanf("%lld%lld", &a, &b);
      Node r = querry(1, 1, n, a, b);
      printf("%lld %lld\n", r.ma.val, r.ma.dir-r.ma.esq+1);
    }
  }

  return 0;
}
