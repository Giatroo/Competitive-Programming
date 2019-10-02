#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a; cin >> b;
    if(b%a == 0 || a%b == 0)
        cout << "Sao Multiplos" << endl;
        else
        cout << "Nao sao Multiplos" << endl;
    return 0;
}
