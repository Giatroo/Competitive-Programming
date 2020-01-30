#include <iostream>

using namespace std;

int main(){
    int n, menor, atual;
    cin >> n;
    cin >> atual;
    menor = atual;
    for (int i = 1; i < n; i++)
    {
        cin >> atual;
        if(atual < menor) menor = atual;
    }
    cout << menor << endl;
}