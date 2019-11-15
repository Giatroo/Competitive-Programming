#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;

ll m[12][12];
ll N;
ll sum;
ll psum;

int main(int argc, char const *argv[]) {
  cin >> N;
  fora(i, N)
    fora(j, N)
      cin >> m[i][j];

  fora(i, N)
  {
    sum += m[0][i];
  }

  forai(i, N-1)
  {
    fora(j, N)
      psum += m[i][j];

    cout << "psum = " << psum << endl;
    if(psum != sum)
    {
      printf("%d\n", -1);
      return 0;
    }
    psum = 0;
  }

  fora(i, N)
  {
    fora(j, N)
      psum += m[j][i];
    cout << "psum = " << psum << endl;
    if(psum != sum)
    {
      printf("%d\n", -1);
      return 0;
    }
    psum = 0;
  }

  fora(i, N)
    psum += m[i][i];
  cout << "psum = " << psum << endl;
  if(psum != sum)
  {
    printf("%d\n", -1);
    return 0;
  }
  psum = 0;

  fora(i, N)
    psum += m[i][N-i-1];
  cout << "psum = " << psum << endl;
  if(psum != sum)
  {
    printf("%d\n", -1);
    return 0;
  }
  psum = 0;

  printf("%lld\n", sum);

  return 0;
}
