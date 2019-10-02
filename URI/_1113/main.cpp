#include <iostream>

using namespace std;

int main()
{
    int a, b;
    while(true)
    {
        cin >> a; cin >> b;
        if(a == b)
            break;
        if(a > b)
            cout << "Decrescente" << endl;
        else
            cout << "Crescente" << endl;
    }
    return 0;
}
