#include <iostream>

using namespace std;

int main()
{
    int a, b, sum = 0;
    cin >> a;
    cin >> b;
    if(a < b)
    {
        for(; a <= b; a++)
        {
            if(a % 13 == 0)
                continue;
            else
                sum += a;
        }
    } else
    {
        for(; b <= a; b++)
        {
            if(b % 13 == 0)
                continue;
            else
                sum += b;
        }
    }
    cout << sum << endl;
    return 0;
}
