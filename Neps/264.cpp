#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll n, k;
char c;
ll x, y;
ll bank[112345];
//ll tam[112345];

void init() {
  forai(i, n) {
    bank[i] = i;
    //tam[i] = 1;
  }
}

ll find(ll a) {
  if (bank[a] == a) return a;
  bank[a] = find(bank[a]);
  return bank[a];
}

void join(ll a, ll b) {
  ll p = find(a);
  ll q = find(b);
  bank[p] = q;
}

void debug() {
  forai(i, n) {
    cout << bank[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  init();
  //debug();
  fora(i, k) {
    cin >> c >> x >> y;
    if (c == 'C') {
      if (find(x) == find(y)) cout << "S" << endl;
      else cout << "N" << endl;
    } else if(c == 'F') {
      join(x, y);
    }
    //debug();
  }


  return 0;
}
