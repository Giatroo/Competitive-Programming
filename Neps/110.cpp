#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int N, tot, max;
  ll cur, ant;
  cin >> N;

  if(N == 0){
    printf("0\n");
    return 0;
  }

  tot = 1;
  max = 1;
  cin >> ant;

  for(int i = 1; i < N; i++)
  {
    cin >> cur;

    //printf("cur = %d ant = %d tot = %d max = %d\n",
    //cur, ant, tot, max);

    if(cur == ant) tot++;
    else {
      if(max < tot) max = tot;
      tot = 1;
    }
    ant = cur;
  }
  if(max < tot) max = tot;

  cout << max << endl;

  return 0;
}
