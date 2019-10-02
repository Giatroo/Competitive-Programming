#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double flag = 0, avg = 0, n;
    while(flag != 2)
    {
        cin >> n;
        if(n < 0 || n > 10)
        {
            cout << "nota invalida" << endl;
            continue;
        } else {
            avg += n;
            flag++;
        }
    }
    cout << "media = " << fixed << setprecision(2) << avg / 2 << endl;
    return 0;
}
