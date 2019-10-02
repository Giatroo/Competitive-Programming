#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int p1, n1, p2, n2;
    double v1, v2;
    cin >> p1;
    cin >> n1;
    cin >> v1;
    cin >> p2;
    cin >> n2;
    cin >> v2;
    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << n1*v1 + n2*v2 << endl;
    return 0;
}
