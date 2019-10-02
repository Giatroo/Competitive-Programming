#include <iostream>

using namespace std;

int main()
{
    int highest = 0, position = 0;
    for(int i = 1; i <= 100; i++){
        int n;
        cin >> n;
        if(n > highest)
        {
            highest = n;
            position = i;
        }
    }
    cout << highest << endl << position << endl;
    return 0;
}
