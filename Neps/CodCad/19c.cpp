#include <bits/stdc++.h>

using namespace std;

int Bs[21];

int main()
{
    int B, N;
    int D, C, V;
    bool S = true;

    cin >> B >> N;
    while (B != 0 && N != 0)
    {
        for (int i = 0; i < B; i++) //linha 1
            cin >> Bs[i];
        for (int i = 0; i < N; i++) //linha 2 .. N+1
        {
            cin >> D >> C >> V;
            Bs[D - 1] -= V;
            Bs[C - 1] += V;
        }

        S = true;
        for (int i = 0; i < B; i++)
        {
            if (Bs[i] < 0)
            {
                S = false;
            }
        }

        if (S == true)
            cout << "S\n";
        else
            cout << "N\n";

        cin >> B >> N;
    }
    return 0;
}