#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double n = 3.14159;
    double radius, area;
    cin >> radius;
    area = n * radius * radius;
    cout << "A=" << fixed << setprecision(4) << area << endl;
    return 0;
}
