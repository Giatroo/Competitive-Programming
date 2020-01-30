#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sq[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> sq[i][j];

    int sum, curSum;
    sum = curSum = 0;

    for(int i = 0; i < n; i++)
    {
        curSum = 0;
        for(int j = 0; j < n; j++)
            curSum += sq[i][j];
        if(sum == 0)
            sum = curSum;
        else if(sum != curSum)
        {
            sum = -1;
            goto endOfProgram;
        }
    }

    for(int j = 0; j < n; j++)
    {
        curSum = 0;
        for(int i = 0; i < n; i++)
            curSum += sq[i][j];
        if(sum != curSum)
        {
            sum = -1;
            goto endOfProgram;
        }
    }


    endOfProgram:
    cout << sum << endl;
    return 0;
}
