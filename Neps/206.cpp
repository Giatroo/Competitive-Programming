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
#define INF LLONG_MAX
#define M 1000000007

using namespace std;

ll n[16], o[8], q[4], s[2], f[1];
ll a, b;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fora (i, 16) get1(n[i]);

  a = 0;
  fora (i, 8) {
    if ((n[a] == 1 && n[a+1] == 9) || (n[a] == 9 && n[a+1] == 1))
    {  cout1e("oitavas"); return 0; }
    if (n[a] == 1 || n[a] == 9) o[i] = n[a];
    else if (n[a+1] == 1 || n[a+1] == 9) o[i] = n[a+1];
    else o[i] = n[a];
    a += 2;
  }

  // fora (i, 8) cout << o[i] << " ";
  // cout << endl;

  a = 0;
  fora (i, 4) {
    if ((o[a] == 1 && o[a+1] == 9) || (o[a] == 9 && o[a+1] == 1))
    {  cout1e("quartas"); return 0; }
    if (o[a] == 1 || o[a] == 9) q[i] = o[a];
    else if (o[a+1] == 1 || o[a+1] == 9) q[i] = o[a+1];
    else q[i] = o[a];
    a += 2;
  }

  // fora (i, 4) cout << q[i] << " ";
  // cout << endl;

  a = 0;
  fora (i, 2) {
    if ((q[a] == 1 && q[a+1] == 9) || (q[a] == 9 && q[a+1] == 1))
    {  cout1e("semifinal"); return 0; }
    if (q[a] == 1 || q[a] == 9) s[i] = q[a];
    else if (q[a+1] == 1 || q[a+1] == 9) s[i] = q[a+1];
    else s[i] = q[a];
    a += 2;
  }

  // fora (i, 2) cout << s[i] << " ";
  // cout << endl;

  cout1e("final");


  return 0;
}
