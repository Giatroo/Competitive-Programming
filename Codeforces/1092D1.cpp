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

//paridade do bloco, paridade do tamanho

ll n, a;
ll len;
pair<ll, ll> aux;

// void showstack(stack <pair<ll, ll>> s)
// {
//     while (!s.empty())
//     {
//         cout << s.top().f << " " << s.top().s << endl;
//         s.pop();
//     }
//     cout << '\n';
// }

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<pair<ll, ll>> w;

  cin >> n;

  cin >> a;
  a %= 2;
  w.push(mp(a, 1));


  forai(i, n-1) {
    cin >> a;
    a %= 2;
    if (w.top().f == a) {
      w.top().s++;
      w.top().s %= 2;
    } else {
      if (w.top().s == 0) {
        w.top().f++;
        w.top().f %= 2;
        w.top().s++;
        w.top().s %= 2;
        aux = w.top();
        w.pop();
        if (!w.empty()) {
          w.top().s += aux.s;
          w.top().s %= 2;
        } else {
          w.push(aux);
        }
      } else {
        w.push(mp(a, 1));
      }
    }
    // cout << "Mostrando a pilha: " << endl;
    // showstack(w);
    // cout << endl;
  }

  if (w.top().s == 0) {
    w.top().f++;
    w.top().f %= 2;
    aux = w.top();
    w.pop();
    if (!w.empty()) {
      w.top().s += aux.s;
      w.top().s %= 2;
    } else {
      w.push(aux);
    }
    // cout << "Mostrando a pilha: " << endl;
    // showstack(w);
    // cout << endl;
  }



  w.pop();
  if (w.empty()) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
