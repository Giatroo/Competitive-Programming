#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    int n100, n50, n20, n10, n5, n2, n1;
    n100 = n / 100;
    n %= 100;
    cout << n100 << " nota(s) de R$ 100,00" << endl;
    n50 = n / 50;
    n %= 50;
    cout << n50 << " nota(s) de R$ 50,00" << endl;
    n20 = n / 20;
    n %= 20;
    cout << n20 << " nota(s) de R$ 20,00" << endl;
    n10 = n / 10;
    n %= 10;
    cout << n10 << " nota(s) de R$ 10,00" << endl;
    n5 = n / 5;
    n %= 5;
    cout << n5 << " nota(s) de R$ 5,00" << endl;
    n2 = n / 2;
    n %= 2;
    cout << n2 << " nota(s) de R$ 2,00" << endl;
    n2 = n / 1;
    cout << n << " nota(s) de R$ 1,00" << endl;
    return 0;
}
