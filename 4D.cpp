#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
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

ll n;
vector<pll> s;
vector<ll> inter, qnt;


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n); s.resize(n); inter.resize(n); qnt.resize(n);
  fora (i, n) { get2(s[i].f, s[i].s); inter[i] = qnt[i] = 0; }
  sortvector(s);

  forita (it, s) {
    cout2e(it->f, it->s);
  }
  cout << endl << endl;

  forita (it, s) {
    for (auto jt = it+1; jt != s.end() && jt->f <= it->s; jt++) {
      if (jt->s > it->s) {
        inter[it - s.begin()] += it->s - jt->f;
        inter[jt - s.begin()] += it->s - jt->f;
      } else {
        inter[it - s.begin()] += jt->s - jt->f;
        inter[jt - s.begin()] += jt->s - jt->f;
      }
      qnt[it - s.begin()]++;
      qnt[jt - s.begin()]++;
    }
    forita (it, inter) { cout << *it << " "; }
    cout << endl << endl;
  }

  ll sum, mini;
  sum = 0; mini = INF;
  forita (it, inter) {
    sum += *it;
    if (*it /**2*/* qnt[it-inter.begin()] < mini)
      mini = *it /**2*/* qnt[it-inter.begin()];
  }

  forita (it, qnt) cout << *it << " ";
  cout << endl;

  cout1e(sum-2*mini);


  return 0;
}

/*
5
10 11
1 8
7 17
15 22
9 12
*/
