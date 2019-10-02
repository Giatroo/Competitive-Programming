#include <iostream>

using namespace std;

int main()
{
    int counting = 0;
    for(int i = 0; i < 5; i++){
        int n;
        cin >> n;
        if(n%2==0)
            counting++;
    }
    cout << counting << " valores pares\n";
    return 0;
}
