#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a; cin >> b; cin >> c;
    if(a+b > c && a+c > b && b+c > a && abs(a-b) < c && abs(b-c) < a && abs(a-c) < b)
    {
        cout << "Perimetro = " << fixed << setprecision(1) << a+b+c << endl;

    }
    else
    {
        cout << "Area = " << fixed << setprecision(1) << (a+b)*c/2 << endl;
    }
    return 0;
}
