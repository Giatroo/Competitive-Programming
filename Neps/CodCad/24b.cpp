#include <bits/stdc++.h>

using namespace std;

int a[112345];

int main()
{
    int n, suml, sumr;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    suml = a[0];
    sumr = a[n - 1];
    int i, j;
    for (i = 0, j = n - 1; i < j-1;)
    {
        if(suml < sumr){
            suml += a[++i];
        } else {
            sumr += a[--j];
        }
        //printf("i = %d j = %d suml = %d sumr = %d\n", i, j, suml, sumr);
    }

    cout << i + 1 << endl;

    return 0;
}