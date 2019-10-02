#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double R;
    cin >> R;
    cout << "VOLUME = " << fixed << setprecision(3) << (4/3.0)*3.14159*R*R*R << endl;
    return 0;
}
