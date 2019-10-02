#include <iostream>

using namespace std;

int main()
{
	int n, p, x, y, soma;
	cin >> n >> p;
	soma = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(x + y >= p)
			soma++;
	}
	cout << soma << endl;
	return 0;
}