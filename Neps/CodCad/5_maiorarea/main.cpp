#include <iostream>

using namespace std;

int main()
{
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int area1, area2;
    area1 = a1*b1;
    area2 = a2*b2;
    if(area1 > area2)
        cout << "Primeiro\n";
    else if(area1 < area2)
        cout << "Segundo\n";
    else if(area1 == area2)
        cout << "Empate\n";
    return 0;
}
