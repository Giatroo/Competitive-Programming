#include <iostream>

using namespace std;

int main()
{
    int a, n = -1, sum = 0;
    cin >> a;
    while(n <= 0)
        cin >> n;
    for(int i = a+n; a < i; a++)
        sum += a;
    cout << sum << endl;
    return 0;
}
