#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a; cin >> b; cin >> c;
    if(b*b - 4*a*c < 0 || a == 0)
        cout << "Impossivel calcular" << endl;
    else
    {
        double x1, x2;
        x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
        x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
        cout << "R1 = " << fixed << setprecision(5) << x1 << endl;
        cout << "R2 = " << fixed << setprecision(5) << x2 << endl;
    }
    return 0;
}
