#include <bits\stdc++.h>

using namespace std;

int main()
{
	int n, m;
	int l, r, x;
	int lowers, value;
	cin >> n >> m;
	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	
	for(int i = 0; i < m; i++)
	{
		cin >> l >> r >> x; // l <= x <= r
		l--; r--; x--;
		lowers = 0;
		value = p[x];
		for(int j = l; j <= r; j++)
			if(p[j] < p[x])
				lowers++;
			
		if(x == lowers + l)
			cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}