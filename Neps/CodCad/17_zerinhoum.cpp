#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b && b == c)
		cout << "*\n";
	else if(a != b && a != c)
		cout << "A\n";
	else if(b != a && b != c)
		cout << "B\n";
	else if(c != a && c != b)
		cout << "C\n";

	return 0;
}