#include <iostream>

using namespace std;

int main()
{
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    if(t1 < t2 && t1 < t3)
    {
        cout << "1" << endl;
        if(t2 < t3)
            cout << "2\n3" << endl;
        else
            cout << "3\n2" << endl;
    } else if(t2 < t1 && t2 < t3)
    {
        cout << "2" << endl;
        if(t1 < t3)
            cout << "1\n3" << endl;
        else
            cout << "3\n1" << endl;
    } else if(t3 < t1 && t3 < t2)
    {
        cout << "3" << endl;
        if(t1 < t2)
            cout << "1\n2" << endl;
        else
            cout << "2\n1" << endl;
    }
    return 0;
}
