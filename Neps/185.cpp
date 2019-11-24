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
#define forita(c) for(auto it = c.begin(); it != c.end(); it++)

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

map<int, int> p;
ll n, aux;
ll a, b, c;


int main(int argc, char const *argv[]) {
  cin >> n;

  fora(i, 5) p[i] = 0;
  a = b = c = 0;


  fora(i, n)
  {
    cin >> aux;

    switch (aux) {
      case 1:
        p[1]++;

        if(p[3] && p[5]) {
          p[1]--;
          p[3]--;
          p[5]--;
          a++;
        } else if(p[4]) {
          p[1]--;
          p[4]--;
          b++;
        }

      break;

      case 2:
        p[2]++;
        if(p[4]) {
          p[2]--;
          p[4]--;
          c++; // > c#
        }

      break;

      case 3:
        p[3]++;
        if(p[1] && p[5]) {
          p[1]--;
          p[3]--;
          p[5]--;
          a++;
        }

      break;

      case 4:
        p[4]++;
        if(p[1]) {
          p[1]--;
          p[4]--;
          b++;
        } else if (p[2]) {
          p[2]--;
          p[4]--;
          c++;
        }


      break;

      case 5:
        p[5]++;
        if (p[1] && p[3]) {
          p[1]--;
          p[3]--;
          p[5]--;
          a++;
        }

      break;
    }

    //switch feio d+ pqp
  }

  cout << "A: " << a << endl << "B: "
  << b << endl << "C: " << c << endl;


  return 0;
}
