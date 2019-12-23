#include <iostream>

using namespace std;

int main()
{
	int cv, ce, cs, fv, fe, fs;
	cin >> cv >> ce >> cs >> fv >> fe >> fs;
	int cp, fp;
	cp = 3*cv + ce;
	fp = 3*fv + fe;

	if(cp > fp)
		cout << "C\n";
	else if(cp < fp)
		cout << "F\n";
	else if(cs > fs)
		cout << "C\n";
	else if(cs < fs)
		cout << "F\n";
	else
		cout << "=\n";

	return 0;
}