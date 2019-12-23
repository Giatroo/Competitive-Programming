#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool s = ((a == b) || (a == b + c) || (b == c) || (b == c + a) || (c == a) || (c == a + b)) ? true : false;
    if(s)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}
