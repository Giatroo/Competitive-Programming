#include <iostream>

using namespace std;

int main(){
    int H, P, F, D;
    cin >> H >> P >> F >> D;
    bool s = ((P < F && F < H) || (F < H && H < P) || (H < P && P < F)) ? true : false;
    bool d = (D == 1) ? true : false;
    if(s == d)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}
