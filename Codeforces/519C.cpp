#include <iostream>

using namespace std;

int main()
{
    int n, m, t = 0;
    int on, om;
    cin >> n >> m;
    on = n;
    om = m;
    if (m > n)
    {
        t = m - n;
        m -= 2 * t;
        n -= t;
    }
    else
    {
        t = n - m;
        n -= 2 * t;
        m -= t;
    }

    if (n < 0)
    {
        if (on > om)
            cout << om << endl;
        else
            cout << on << endl;
    }
    else
    {
        cout << t + (n + m) / 3 << endl;
    }

}