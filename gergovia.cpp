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

ll n;
ll tot;
int a[112345];

void printArray(int n)
{
  fora(i, n) cout << a[i] << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  cin >> n;
  while(n != 0)
  {
    tot = 0;
    fora(i, n) cin >> a[i];

    fora(i, n) {
      ll j = i+1;
      //printf("a[%lld] = %d\n", i, a[i]);
      while (a[i]) {
        if(a[j] * a[i] < 0){
          tot += min(abs(a[i]), abs(a[j])) * (j-i);
          if(abs(a[j]) < abs(a[i]))
          {
            a[i] += a[j];
            a[j] = 0;
          } else {
            a[j] += a[i];
            a[i] = 0;
          }
        }
        j++;
        //printArray(n);
      }
    }
    cout << tot << endl;
    cin >> n;
  }
  return 0;
}
