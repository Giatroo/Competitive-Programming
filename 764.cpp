#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define debug(x) #x << " = " << x << " "

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

map<string, int> points;
map<string, int> lastmsg;
vector<pair<int, string>> v;
int n, m;
string s;
int t;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
  if (p1.f == p2.f) return p1.s > p2.s;
  return p1.f < p2.f;
}

int main(int argc, char const *argv[]) { fastio;
  cin >> n >> m;
  fr (i, n) {
    cin >> s >> t;
    if (points[s] == 0 || t >= lastmsg[s] + m) {
      points[s] += 25;
      lastmsg[s] = t;
    }
  }

  frit (it, points) {
    v.push_back(make_pair(it->s, it->f));
  }
  sortvectorby(v, cmp);


  cout << "--Rank do Nepscord--" << endl;
  int i = 0;
  auto it = v.end();
  it--;
  for (; ; it--) {
    cout << "#" << ++i << ". " << it->s << " - Nivel " << it->f/100+1 << endl;
    if (i == 3) break;
    if (it == v.begin()) break;
  }
  for (; i < 3; i++) cout << "#" << ++i << "." << endl;


  // cout << "v:" << endl;
  // frit (it, v) cout << it->f << " " << it->s << endl;

  // cout << endl << "lastmsg:" << endl;
  // frit (it, lastmsg) cout << it->f << " " << it->s << endl;

  return 0;
}
