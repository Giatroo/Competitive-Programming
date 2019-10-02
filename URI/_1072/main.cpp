#include <iostream>

using namespace std;

int main()
{
    int total, in=0, out=0;
    cin >> total;
    for(int i = 0; i < total; i++){
        int n;
        cin >> n;
        if(10 <= n && n <= 20)
            in++;
        else
            out++;
    }
    cout << in << " in\n" << out << " out\n";
    return 0;
}
