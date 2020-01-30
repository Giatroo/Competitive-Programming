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

bool prime[1312345];
ll q, p;
map<ll, ll> primes;
ll numP;
ll maxP;

void sieve(ll n) {
  ll i, c;
  for (i = maxP+1; i <= n; i++) {
    if (prime[i]) {
      primes[i] = numP++;
      maxP = i;
      for (ll j = 2*i; j <= 1300100; j += i)
        prime[j] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get1(q);

  forai (i, 1300100) prime[i] = true;
  prime[1] = false;
  maxP = 1;
  numP = 1;

  fora(i, q) {
    get1(p);
    if (maxP > p) cout1e(primes[p]);
    else { sieve(p); cout1e(primes[p]); }
  }


  return 0;
}
