#include <iostream>

using namespace std;

int main()
{
    int a, b, sum;
    while(true)
    {
        sum = 0;
        cin >> a; cin >> b;
        if(a <= 0 || b <= 0)
            break;
        if(a > b) // 3 1
        {
            for(; b <= a; b++)
            {
                cout << b << " ";
                sum += b;
            }
        } else
        {
            for(; a <= b; a++)
            {
                cout << a << " ";
                sum += a;
            }
        }
        cout << "Sum=" << sum << endl;
    }
    return 0;
}
