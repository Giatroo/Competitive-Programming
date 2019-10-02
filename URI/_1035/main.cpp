#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A; cin >> B; cin >> C; cin >> D;
    if(B > C && D > A && C+D > A+B && C > 0 && D > 0 && A%2==0)
    {
        cout << "Valores aceitos" << endl;
    } else {
        cout << "Valores nao aceitos" << endl;
    }
    return 0;
}
