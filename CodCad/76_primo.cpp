#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	bool isPrime = (n != 1);

	for(long long i = 2; i*i <= n && isPrime; i++)
		isPrime = (n % i != 0);

	if(isPrime) cout << "S\n";
	else cout << "N\n";

	return 0;
}