#include <iostream>

using namespace std;

int main()
{
    int n, counting = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        if(s[i] == s[i+1])
            counting++;
    cout << counting << endl;
    return 0;
}
