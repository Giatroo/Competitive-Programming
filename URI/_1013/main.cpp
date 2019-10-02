#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a; cin >> b; cin >> c;
    int maiorAB = (a+b+abs(a-b))/2;
    int maior = (maiorAB+c+abs(maiorAB-c))/2;
    cout << maior << " eh o maior" << endl;
    return 0;
}
