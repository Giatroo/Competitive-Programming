#include <iostream>

using namespace std;

bool isCoprime(int a, int b)
{
    int rest;
    while(b != 0)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    if(a == 1)
        return true;
    return false;
}

int main()
{
    int n, a, b, amax, bmax;
    cin >> n;
    //a and b must be coprimes and a+b should be equal to n
    a = 1;
    b = n - 1;
    while(a < b)
    {
        if(isCoprime(a, b))
        {
            amax = a;
            bmax = b;
        }
        a++; b--;
    }
    cout << amax << " " << bmax << endl;
    return 0;
}
