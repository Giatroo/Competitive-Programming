#include <iostream>

using namespace std;

int main()
{
    int s, e, l;
    cin >> s; cin >> e;
    if(s == e)
        l = 24;
    else if(s < e)
        l = e-s;
    else
        l=24-s+e;
    cout << "O JOGO DUROU " << l << " HORA(S)" << endl;
    return 0;
}
