#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        if(m%2==0)
        {
            if(m>0)
                cout << "EVEN POSITIVE\n";
            else if(m==0)
                cout << "NULL\n";
            else if(m<0)
                cout << "EVEN NEGATIVE\n";
        } else {
            if(m>0)
                cout << "ODD POSITIVE\n";
            else
                cout << "ODD NEGATIVE\n";
        }
    }
    return 0;
}
