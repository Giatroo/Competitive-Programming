#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int time, speed;
    double yield = 1/12; // l/km
    cin >> time; cin >> speed;
    cout << fixed << setprecision(3) << 1.0/12 * time * speed << endl;
    return 0;
}
