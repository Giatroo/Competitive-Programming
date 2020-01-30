#include <iostream>

using namespace std;

int main(){
    int n, s, sa, menor;

    cin >> n >> s;
    menor = s;
    while(n > 0){
        n--;
        cin >> sa;
        s += sa;
        if(s < menor)
            menor = s;
    }
    cout << menor << endl;
}