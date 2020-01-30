#include <iostream>

using namespace std;

int main()
{
	int h1, m1, h2, m2;
	int mt1, mt2;
	int resp;
	cin >> h1 >> m1 >> h2 >> m2;
	while(h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)
	{
		mt1 = h1 * 60 + m1;
		mt2 = h2 * 60 + m2;
		if(mt1 <= mt2)
			resp = mt2 - mt1;
		else
			resp = 24*60 - mt1 + mt2;
		cout << resp << endl;
		cin >> h1 >> m1 >> h2 >> m2;
	}
	return 0;
}