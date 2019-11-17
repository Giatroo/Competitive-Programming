#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

ll p, s;
typedef pair<ll, ll> inter;
ll x, y;
vector<inter> inters;
vector<inter> intersf;
inter interv;


int main(int argc, char const *argv[]) {
  cin >> p >> s;

  fora(i, s)
  {
    cin >> x >> y;
    inters.push_back(make_pair(x, y));
  }

  sortvector(inters);

  intersf.push_back(inters[0]);
  forai(i, s-1)
  {
    if(inters[i].f <= intersf.back().s)
    {
      interv = make_pair(intersf.back().f,
      max(intersf.back().s, inters[i].s));
      intersf.pop_back();
      intersf.push_back(interv);
    } else {
		  intersf.push_back(inters[i]);
	  }
  }

  fora(i, intersf.size())
    printf("%lld %lld\n", intersf[i].f, intersf[i].s);

  return 0;
}
