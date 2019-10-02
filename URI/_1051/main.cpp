#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double salary;
    cin >> salary;
    double tax = 0;

    if(salary - 2000 <= 0){
        tax = 0;
    } else if(salary > 2000 && salary <= 3000)
    {
        tax += (salary - 2000) * 0.08;
    } else if(salary > 3000 && salary <= 4500)
    {
         tax += (salary - 3000) * 0.18;
         tax += (1000) * 0.08;
    } else if(salary > 4500)
    {
        tax += (salary - 4500) * 0.28;
        tax += (1500) * 0.18;
        tax += (1000) * 0.08;
    }
    if(tax != 0)
        cout << "R$ " << fixed << setprecision(2) << tax << endl;
    else
        cout << "Isento" << endl;
    return 0;
}
