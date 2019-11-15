#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)

using namespace std;

typedef struct {
  ll l, r, f;
} Faicha;

Faicha A[112345];

ll N, M, O;

ll bb(ll v)
{
  ll l, r, m;
  l = 0;
  r = N - 1;
  m = (l+r)/2;
  while(l <= r)
  {
    if(v < A[m].l) r = m - 1;
    else if(v >= A[m].r) l = m + 1;
    else break;
    m = (l+r)/2;
  }

  return A[m].f;
}

int main(int argc, char const *argv[]) {
  /* Montando os intervalos */
  cin >> N >> M;
  A[0].l = 1;
  cin >> A[0].r;
  A[1].l = A[0].r;

  for(ll i = 1; i <= N-2; i++)
  {
    cin >> A[i].r;
    A[i+1].l = A[i].r;
  }

  A[N-1].r = INT_MAX;

  fora(i, N)
    cin >> A[i].f;

  A[0].r--;

  /* Fim montando os intervalos */
  fora(i, M-1)
  {
    cin >> O;
    cout << bb(O) << " ";
  }
  cin >> O;
  cout << bb(O) << endl;

  return 0;
}
