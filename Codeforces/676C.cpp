#include <bits/stdc++.h>
using namespace std;

string s;

int verificaPara(char letra, int k, int n)
{
	int l, r, max;
	l = r = max = 0;
	while(r < n)
	{
		if(k == 0 && s[r] == letra)
		{
			if(s[l] == letra) k++;		
			l++;
		} else {
			if(s[r] == letra) k--;
			r++;
		}
		if(r - l > max) max = r - l;
	}
	return max;	
}

int main()
{
	int max, c;
	int k, n;
	cin >> n >> k;
	cin >> s;

	max = verificaPara('a', k, n);
	c = verificaPara('b', k, n);
	if(c > max) max = c;

	cout << max << endl;

	return 0;
}
