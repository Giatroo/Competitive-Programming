#include <iostream>

using namespace std;

int main()
{
    int P, R;
    cin >> P >> R;
    if(!P)
        cout << "C" << endl;
    else if(!R)
        cout << "B" << endl;
    else
        cout << "A" << endl;

    return 0;
}
