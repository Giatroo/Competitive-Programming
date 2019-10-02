#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a = 0, b = 0, sum = 0;
        cin >> a; cin >> b;
        if(a > b) //15 2
        {
            if(b % 2 == 0)
                b+=1;
            else
                b+=2;
            for(int j = b; b < a; b += 2)
                sum += b;
        } else
        {
            if(a % 2 == 0)
                a+=1;
            else
                a+=2;
            for(int j = a; a < b; a += 2)
                sum += a;
        }
        cout << sum << endl;

    }
    return 0;
}
