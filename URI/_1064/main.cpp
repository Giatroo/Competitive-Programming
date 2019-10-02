#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int counting = 0;
    double sum = 0;
    for(int i = 0; i < 6; i++){
        double n;
        cin >> n;
        if(n > 0)
        {
            counting++;
            sum += n;
        }
    }
    cout << counting << " valores positivos\n";
    cout << fixed << setprecision(1) << sum / counting << endl;
    return 0;
}
