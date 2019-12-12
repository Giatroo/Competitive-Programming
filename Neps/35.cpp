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

int a, b, c, d;
int L, C;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b >> c >> d;
  L = a + b;
  C = c + d;
  if (a == b) L *= 2;
  else if(abs(a - b) == 1) L *= 3;
  if (c == d) C *= 2;
  else if(abs(c - d) == 1) C *= 3;

  if (L == C) cout << "empate\n";
  else if (L > C) cout << "Lia\n";
  else cout << "Carolina\n";


  return 0;
}
