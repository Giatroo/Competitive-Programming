#include <iostream>

using namespace std;

int main()
{
    int n = -1, alcool = 0, gas = 0, diesel = 0;
    while(n != 4)
    {
        cin >> n;
        switch(n)
        {
            case 1:
                alcool++;
                break;
            case 2:
                gas++;
                break;
            case 3:
                diesel++;
                break;
        }
    }
    cout << "MUITO OBRIGADO\nAlcool: " << alcool << "\nGasolina: " << gas << "\nDiesel: " << diesel << endl;
    return 0;
}
