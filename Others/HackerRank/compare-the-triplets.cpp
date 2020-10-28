/*******************************************************************************
  My template for competitive programming competitions and practices
  -----------------------------------------------------

Programmer:     Lucas Paiolla Forastiere
Last change:    2020-10-26

This file is a template created by me to help with competitive programming.
Whenever I need to create a new file to a problem, I copy this template and
just start coding (I even have a bash script that I can call the already puts
me inside vim).
Feel free to copy get some inspiration from my template. I'm always trying to
improve it.
*******************************************************************************/

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

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for (auto it = c.begin(); it != c.end(); it++)

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
// ========================================================================== //

int main(int argc, char const *argv[]) {
  fastio;
  ll a[3], b[3];
  ll p1, p2;
  cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
  p1 = p2 = 0;

  fr(i, 3) if (a[i] > b[i]) p1++;
  else if (a[i] < b[i]) p2++;

  cout << p1 << ' ' << p2 << endl;

  return 0;
}
