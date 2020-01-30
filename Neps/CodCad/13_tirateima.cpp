#include <iostream>

using namespace std;

int main()
{
	int x, y;
	bool fora = false;
	cin >> x >> y;
	fora = (x < 0 || x > 432 || y < 0 || y > 468);
	if(fora)
		cout << "fora\n";
	else 
		cout << "dentro\n";

	return 0;
}