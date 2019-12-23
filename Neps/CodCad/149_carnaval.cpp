#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double n[5];
	double maior, menor;
	int imaior, imenor;
	cin >> n[0];
	imaior = imenor = 0;
	maior = menor = n[0];
	for(int i = 1; i < 5; i++)
	{
		cin >> n[i];
		if(n[i] < menor)
		{
			menor = n[i];
			imenor = i;
		}
		if(n[i] > maior)
		{
			maior = n[i];
			imaior = i;
		}
	}

	double soma = 0;
	for(int i = 0; i < 5; i++)
	{
		if(i != imenor && i != imaior)
			soma += n[i];
	}

	cout << fixed;
    cout << setprecision(1);
    cout << soma << endl;

	return 0;
}