#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string name;
    double salary, sell;
    cin >> name;
    cin >> salary;
    cin >> sell;
    cout << "TOTAL = R$ " << fixed << setprecision(2) << salary + 0.15*sell << endl;
    return 0;
}
