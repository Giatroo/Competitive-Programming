#include <iostream>

using namespace std;

int main()
{
    for(int i = 1, j = 7; i <= 9; i+=2){
        for(int k = j; k > j-3; k--){
            cout << "I=" << i << " J=" << k << endl;
        }
        j +=2;
    }
    return 0;
}
