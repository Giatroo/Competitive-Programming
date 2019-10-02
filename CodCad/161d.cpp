#include <bits/stdc++.h>

using namespace std;

int Bs[91];
bool Ns[91];

int main()
{
    int N, B;
    bool Y;
    cin >> N >> B;
    while (N * B != 0)
    {
        for (int i = 0; i < B; i++)
            cin >> Bs[i];
        for (int i = 0; i < N; i++)
            Ns[i] = false;

        for (int i = 0; i < B; i++)
            for (int j = i; j < B; j++){
                Ns[abs(Bs[i]-Bs[j])] = true;
            }

        Y = true;
        for(int i = 0; i < N && Y; i++){
            //printf("Ns[%d] = %d\n", i, Ns[i]);
            Y = Ns[i];
        }

        if(Y) cout << "Y\n";
        else cout << "N\n";
        
        cin >> N >> B;
    }

    return 0;
}