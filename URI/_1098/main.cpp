#include <iostream>

using namespace std;

int main()
{
    for(double i = 0; i <= 2; i += 0.2)
    {
        for(double j = i + 1; j <= (i + 3); j++)
        {
            cout << "I=" << i << " J=" << j << endl;
        }
    }
    return 0;
}
