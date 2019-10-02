#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a; cin >> b;
    if(a < b)
    {
        a++;
        for(; a < b; a++)
            if(a % 5 == 2 || a % 5 == 3)
                cout << a << endl;
    } else
    {
        b++;
        for(; b < a; b++)
            if(b % 5 == 2 || b % 5 == 3)
                cout << b << endl;
    }
    return 0;
}
