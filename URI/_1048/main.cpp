#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double salary;
    cin >> salary;
    double newsalary, increment, perc;
    if(0 <= salary && salary <= 400.00)
        perc = 0.15;
     else if(400.01 <= salary && salary <= 800.00)
        perc = 0.12;
     else if(800.01 <= salary && salary <= 1200.00)
        perc = 0.10;
     else if(1200.01 <= salary && salary <= 2000.00)
        perc = 0.07;
     else if(2000.00 <= salary)
        perc = 0.04;

    increment = salary * perc;
    newsalary = salary + increment;

    cout << "Novo salario: " << fixed << setprecision(2) << newsalary <<
    "\nReajuste ganho: " << fixed << setprecision(2) << increment <<
     "\nEm percentual: " << fixed << setprecision(0) << perc*100 << " %" << endl;

    return 0;
}
