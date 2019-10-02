#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num, hours;
    double value;
    cin >> num;
    cin >> hours;
    cin >> value;
    cout << "NUMBER = " << num << endl << "SALARY = U$ " << fixed << setprecision(2) << hours*value << endl;
    return 0;
}
