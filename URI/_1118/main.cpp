#include <iostream>
#include <iomanip>

using namespace std;

void novo();
void media();

void novo()
{
    int n;
    cout << "novo calculo (1-sim 2-nao)" << endl;
    cin >> n;
    if(n != 1 && n != 2)
    {
        novo();
        return;
    } else
    {
        if(n == 1)
            media();
        else
            return;
    }
}

void media()
{
    double flag = 0, n, sum = 0;
    while(flag != 2)
    {
        cin >> n;
        if(n < 0 || n > 10)
        {
            cout << "nota invalida" << endl;
            continue;
        }
        sum += n;
        flag++;
    }
    cout << "media = " << fixed << setprecision(2) << sum / 2.0 << endl;
    novo();
}

int main()
{
    media();
    return 0;
}
