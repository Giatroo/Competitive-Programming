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

int det(int m[][3]){
	return m[0][0]*m[1][1]*m[2][2] +
         m[0][1]*m[1][2]*m[2][0] +
         m[0][2]*m[1][0]*m[2][1] -
         m[0][0]*m[1][2]*m[2][1] -
         m[0][1]*m[1][0]*m[2][2] -
         m[0][2]*m[1][1]*m[2][0];
}

int main(){

	int m[3][3];

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin >> m[i][j];

	cout << det(m) << "\n";
  return 0;
}
