#include <iostream>

using namespace std;

int main()
{
    int a;
    while(true)
    {
        cin >> a;
        if(a == 2002)
        {
            cout << "Acesso Permitido" << endl;
            break;
        } else
        {
            cout << "Senha Invalida" << endl;
        }
    }
    return 0;
}
