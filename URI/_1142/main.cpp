#include <iostream>

using namespace std;

int main()
{
    int n, j = 1;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < 3; k++, j++)
        {
            if(j % 4 == 0)
                cout << "PUM" << endl;
            else
                cout << j << " ";
        }
    }
    return 0;
}
