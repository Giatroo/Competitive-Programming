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

ll n;

void mergesort(vector<ll> &v) {
  // cout << "Entrando: ";
  // forita (it, v) cout1(*it) << " ";
  // cout << endl << endl;


  if (v.size() == 1) {
    // cout << "Saindo: ";
    // forita (it, v) cout1(*it) << " ";
    // cout << endl << endl;
    return;
  }

  vector<ll> v1, v2;
  ll m = (v.size())/2;
  fora (i, m) v1.pb(v[i]);
  for (ll i = m; i <= v.size()-1; i++) v2.pb(v[i]);

  mergesort(v1);
  mergesort(v2);

  v1.pb(MINF);
  v2.pb(MINF);

  ll ini1, ini2;
  ini1 = ini2 = 0;

  for (ll i = 0; i < v.size(); i++) {
    if (v1[ini1] > v2[ini2]) v[i] = v1[ini1++];
    else v[i] = v2[ini2++];
  }

  // cout << "Saindo: ";
  // forita (it, v) cout1(*it) << " ";
  // cout << endl << endl;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(n);
  vector<ll> a;
  fora (i, n) { ll b; get1(b); a.pb(b); }
  mergesort(a);
  forita (it, a) cout1(*it) << " ";
  cout << endl;

  return 0;
}
