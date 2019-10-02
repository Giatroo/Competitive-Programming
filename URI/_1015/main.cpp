#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;
    cout << fixed << setprecision(4) << sqrt(pow(x1-x2, 2)+pow(y1-y2, 2)) << endl;
}
