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

#define ull unsigned long long int

string a, b;
ull ca, cb;
ull c;
ll numc;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(a, b);
  while (a[0] != '0' && b[0] != '0') {
    numc = 0;
    c = 0;
    if (a.size() < b.size()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    fora (i, b.size()) {
      ca = a[i] - '0';
      cb = b[i] - '0';
      if (ca + cb + c >= 10) {
        numc++;
        c = 1;
        // cout2e(ca, cb);
        // cout2e(numc, "no primeiro.");
      } else c = 0;
    }

    for (ll i = b.size(); a[i] == '9' && c == 1; i++, numc++);

    if (numc == 0) cout << "No carry operation.";
    else if (numc == 1) cout << "1 carry operation.";
    else cout << numc << " carry operations.";
    cout << endl;

    get2(a, b);
  }

  return 0;
}
