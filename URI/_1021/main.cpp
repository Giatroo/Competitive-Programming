#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double N;
    cin >> N;
    int banknote;
    double fractional;
    banknote = floor(N);
    fractional = N - banknote;
    int coins = fractional * 100;
    cout << "NOTAS:\n";
    int n100, n50, n20, n10, n5, n2, n1;
    n100 = banknote / 100;
    banknote %= 100;
    cout << n100 << " nota(s) de R$ 100.00" << endl;
    n50 = banknote / 50;
    banknote %= 50;
    cout << n50 << " nota(s) de R$ 50.00" << endl;
    n20 = banknote / 20;
    banknote %= 20;
    cout << n20 << " nota(s) de R$ 20.00" << endl;
    n10 = banknote / 10;
    banknote %= 10;
    cout << n10 << " nota(s) de R$ 10.00" << endl;
    n5 = banknote / 5;
    banknote %= 5;
    cout << n5 << " nota(s) de R$ 5.00" << endl;
    n2 = banknote / 2;
    banknote %= 2;
    cout << n2 << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:\n";
    cout << banknote <<  " moeda(s) de R$ 1.00" << endl;
    int m50, m25, m10, m5, m1;
    m50 = coins / 50;
    coins %= 50;
    cout << m50 << " moeda(s) de R$ 0.50" << endl;
    m25 = coins / 25;
    coins %= 25;
    cout << m25 << " moeda(s) de R$ 0.25" << endl;
    m10 = coins / 10;
    coins %= 10;
    cout << m10 << " moeda(s) de R$ 0.10" << endl;
    m5 = coins / 5;
    coins %= 5;
    cout << m5 << " moeda(s) de R$ 0.05" << endl;
    cout << coins << " moeda(s) de R$ 0.01" << endl;
    return 0;
}
