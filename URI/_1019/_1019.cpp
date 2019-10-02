#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int h, m, s;
    h = N / 3600;
    N %= 3600;
    m = N / 60;
    N %= 60;
    s = N;
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}
