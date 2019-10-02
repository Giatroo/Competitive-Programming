#include <iostream>

using namespace std;

int main()
{
    int x, y, sum=0;
    cin >> x; cin >> y; // x = 6 , y = -5
    if(x > y)
    {
        if(y%2==0)
            y++;
        else
            y+=2;
        for(int i = y; i < x; i+=2)
        {
            sum +=i;
        }
    } else{
        if(x%2==0)
            x++;
        else
            x+=2;
        for(int i = x; i < y; i+=2)
        {
            sum +=i;
        }
    }
    cout << sum << endl;
    return 0;
}
