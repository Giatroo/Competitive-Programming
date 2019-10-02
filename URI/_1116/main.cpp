#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a; cin >> b;
        if(b == 0)
        {
            cout << "divisao impossivel" << endl;
            continue;
        }
        double d = (double)a / b;
        cout << fixed << setprecision(1) << d << endl;
    }
    return 0;
}
