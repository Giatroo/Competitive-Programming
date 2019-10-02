#include <iostream>

using namespace std;

int main(){
    long long n, a, dias;
    long long meta = 1000000;
    dias = 0;
    cin >> n;
    while(n > 0){
        cin >> a;
        if(meta > 0)
            dias++;
        meta -= a;
        n--;
    }
    cout << dias << endl;
}