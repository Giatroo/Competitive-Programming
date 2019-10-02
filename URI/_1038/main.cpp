#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int X, Y;
    double value;
    cin >> X; cin >> Y;
    switch(X)
    {
    case 1:
        value = 4;
        break;
    case 2:
        value = 4.5;
        break;
    case 3:
        value = 5;
        break;
    case 4:
        value = 2;
        break;
    case 5:
        value = 1.5;
        break;
    }
    cout << "Total: R$ " << fixed << setprecision(2) << value * Y << endl;
    return 0;
}
