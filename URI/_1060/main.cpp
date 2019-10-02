#include <iostream>

using namespace std;

int main()
{
    int counting = 0;
    for(int i = 0; i < 6; i++){
        double n;
        cin >> n;
        if(n > 0)
            counting++;
    }
    cout << counting << " valores positivos\n";
    return 0;
}
