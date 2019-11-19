#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
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

vector<ll> vet;
ll n;
ll a;

void mergesort(vector<ll> &v)
{
  if(v.size() == 1) return;

  vector<ll> u1, u2;
  fora(i, v.size()/2) u1.push_back(v[i]);
  for(int i = v.size()/2; i < v.size(); i++) u2.push_back(v[i]);

  /*cout << "u1 = ";
  fora(i, u1.size()) cout << u1[i] << " ";
  cout << endl;
  cout << "u2 = ";
  fora(i, u2.size()) cout << u2[i] << " ";
  cout << endl;*/

  mergesort(u1);
  mergesort(u2);

  ll j, k;
  k = j = 0;

  fora(i, v.size())
  {
    if (j == u1.size() && k == u2.size()) break;
    else if(j == u1.size()) {
      v[i] = u2[k++];
    } else if(k == u2.size()) {
      v[i] = u1[j++];
    } else {
      if(u1[j] >= u2[k]) v[i] = u1[j++];
      else v[i] = u2[k++];
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> n;
  vet.resize(n);
  fora(i, n) cin >> vet[i];
  mergesort(vet);
  fora(i, vet.size()) cout << vet[i] << " ";
  cout << endl;
  return 0;
}
