#include <iostream>

using namespace std;

int main()
{
    int n, counter = 0;
    cin >> n;
    string gab, ans;
    cin >> gab >> ans;
    for(int i = 0; i < n; i++)
        if(gab[i] == ans[i])
            counter++;
    cout << counter << endl;

    return 0;
}
