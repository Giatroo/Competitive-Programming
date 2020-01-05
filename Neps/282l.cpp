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

queue<pair<ll, ll>> fila;
priority_queue<ll> caixas;
ll c, n;
ll t, d;
ll counter, cur;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> c >> n;
  counter = 0;
  fora(i, c) caixas.push(0);
  fora(i, n) {
    cin >> t >> d;
    cur = -caixas.top();
    caixas.pop();
    //cout << "cur = " << cur << endl;
    if (t + 20 < cur) {
      counter++;
      //cout << "contou" << endl;
    }
    caixas.push(-max(cur + d, t + d));
  }

  cout << counter << endl;


  return 0;
}
