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
#define M 10e9+7
#define MINF -M

using namespace std;

#define  pL pair< pll, pll >

ll times, n, q;
pL  t[4*112345];
ll v[112345];
ll a, b;

void build(ll l, ll r, ll i)
{
  if (l == r) t[i] = mk(mk(v[l], v[l]), mk(l, r));
  else {
    ll m = l + (r-l)/2;
    ll lc, rc;
    lc = 2*i; rc = 2*i+1;
    build(l, m, lc);
    build(m+1, r, rc);

    t[i] = (t[lc].f.s > t[rc].f.s) ? t[lc] : t[rc];
    t[i] = (t[lc].f.f + t[rc].f.f >= t[i].f.s) ?
            mk(mk((ll)1, t[lc].f.f + t[rc].f.f),
               mk(l, r)) : t[i];
    if ((t[lc].s.s == t[rc].s.f - 1) &&
        (t[lc].f.s + t[rc].f.s >= t[i].f.s))
        t[i] = mk(mk((ll)1, t[lc].f.s + t[rc].f.s),
                  mk(t[lc].s.f, t[rc].s.s));
    t[i].f.f = t[lc].f.f + t[rc].f.f;
  }
}

pL query(ll l, ll r, ll i, ll ql, ll qr)
{
  // cout << "Entrando com " << l << " " << r << " " << i << endl;
  if (l > qr || r < ql) {
    // cout << "Outside" << endl;
    return mk(mk(MINF, MINF), mk(l, r));
  }

  if (ql <= l && r <= qr) {
    // cout << "Retornando " <<
    //   t[i].f.f << " " << t[i].f.s << " " <<
    //   t[i].s.f << " " << t[i].s.s << endl;
    return t[i];
   }

  ll m = l + (r-l)/2;
  pL t1, t2, t3;
  ll lc, rc;
  lc = 2*i; rc = 2*i+1;
  t1 = query(l, m, lc, ql, qr);
  t2 = query(m+1, r, rc, ql, qr);

  // cout << "t1 = " << t1.f.f << " " << t1.f.s
  //      << " " << t1.s.f << " " << t1.s.s << endl;
  // cout << "t2 = " << t2.f.f << " " << t2.f.s
  //      << " " << t2.s.f << " " << t2.s.s << endl;

  t3 = (t1.f.s > t2.f.s) ? t1 : t2;

  if (t1.f.f != MINF  && t2.f.f != MINF) {
    t3 = (t1.f.f + t2.f.f >= t3.f.s) ?
            mk(mk((ll)1, t1.f.f + t2.f.f),
               mk(t1.s.f, t2.s.s)) : t3;
    if ((t1.s.s == t2.s.f - 1) &&
        (t1.f.s + t2.f.s >= t3.f.s))
        t3 = mk(mk((ll)1, t1.f.s + t2.f.s),
                  mk(t1.s.f, t2.s.s));
    t3.f.f = t1.f.f + t2.f.f;
  }

  // cout << "Retornando " <<
  //   t3.f.f << " " << t3.f.s << " " <<
  //   t3.s.f << " " << t3.s.s << endl;

  return t3;
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  get1(times);
  fora (k, times) {
    get1(n);
    forai (i, n) get1(v[i]);
    build(1, n, 1);

    // forai (i, 3*n) cout3(t[i].f.f, t[i].f.s, t[i].s.f) << " " << t[i].s.s << endl;

    get1(q);
    fora (i, q) {
      get2(a, b);
      pL tu = query(1, n, 1, a, b);
      // cout3(tu.f.f, tu.f.s, tu.s.f) << " " << tu.s.s << endl;
      printf("%lld %lld\n", tu.f.s, tu.s.s - tu.s.f + 1);
      // cout2e(tu.f.s, tu.s.s - tu.s.f + 1);
    }
  }

  return 0;
}
