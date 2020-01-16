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
#define M 1000000007

using namespace std;

ll n, a;
ll c[112345];
ll h[11234];
ll maxh;
lld const delta = 10e-6;

lld getArea(lld height) {
  return h[(int)ceil(height)] +
  (1-(height-floor(height)))*(h[(int)floor(height)]-h[(int)ceil(height)]);
}

lld bs(lld l, lld r, lld x) {

  lld maxh = r;
  ll it = 0;
  lld m = l + (r-l)/2;

  if (getArea(0) == x) return -1; // smile face
  else if (getArea(0) < x) return -2; // sad face

  while (it <= 10000) {
    m = l + (r-l)/2;
    // cout3(l, m, r) << " " << getArea(m) << endl;
    if (getArea(m) > x) l = m;
    else r = m;
    it++;
  }

  return m;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // FILE *f;
  // f = fopen("out.txt", "w");

  get2(n, a);
  while (n != 0 && a != 0) {
    maxh = 0;
    fora (i, n) {
      get1(c[i]);
      maxh = max(maxh, c[i]);
    }

    fora (i, maxh+1) h[i] = 0;
    fora (i, n) {
      h[0]++;
      h[c[i]]--;
    }
    forai (i, maxh) h[i] += h[i-1];

    // cout << endl;
    // fora (i, maxh+1) cout1(h[i]) << " ";
    // cout << endl;

    for (ll i = maxh; i >= 0; i--)
      h[i] = h[i] + h[i+1];

    // cout << endl;
    // fora (i, maxh+1) cout1(h[i]) << " ";
    // cout << endl;
    //
    // cout2e("Area of 4", getArea(4));
    // cout2e("Area of 4.5", getArea(4.5));
    // cout2e("Area of 4.25", getArea(4.25));
    // cout2e("Area of 0", getArea(0));
    // cout2e("Area of 6", getArea(6));
    // cout2e("Area of 1", getArea(1));

    // for (lld i = maxh; i >= 0; i -= 0.1)
    //   cout2e(i, getArea(i));

    lld ans = bs(0, maxh, a);

    if (abs(ans - (-1)) <= delta) cout1e(":D");
      // fprintf(f, ":D\n");
    else if (abs(ans - (-2)) <= delta) cout1e("-.-");
      // fprintf(f, "-.-\n");
    else cout << setprecision(4) << fixed << ans << endl;
      // fprintf(f, "%.4Lf\n", ans);

    get2(n, a);
  }
  // fclose(f);

  return 0;
}
