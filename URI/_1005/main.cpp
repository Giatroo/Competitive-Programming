#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    double a, b;
    cin >> a;
    cin >> b;
    cout << "MEDIA = " << fixed << setprecision(5) << ((a*3.5)+(b*7.5))/11 << endl;
    return 0;
}
