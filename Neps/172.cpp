#include <bits/stdc++.h>
using namespace std;

int a[11234];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    cout << a[n-1] << endl << a[0] << endl;
    return 0;
}
