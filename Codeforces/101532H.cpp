#include <iostream>

using namespace std;

int main()
{
    int tests, n, m, sum, missing;
    char aux;
    cin >> tests;
    for (int k = 0; k < tests; k++)
    {
        cin >> n >> m;
        int bin[n][m];
        sum = 0;
        missing = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> aux;
                bin[i][j] = aux - '0';
                sum += bin[i][j];
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !bin[i][j])
                {
                    missing++;
                }
            }
        }

        cout << sum << endl;
        if (sum < n * m)
        {
            cout << -1 << endl;
            continue;
        }
        if (!missing)
            cout << 0 << endl;
        else
        {
            cout << missing << endl;
        }
    }
    return 0;
}