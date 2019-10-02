#include <iostream>

using namespace std;

int main(){
    int n, tatu, tant, total;
    cin >> n >> tant;
    total = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> tatu;
        if(tatu - tant >= 10)
            total += 10;
        else
            total += (tatu - tant);
        tant = tatu;
    }
    total += 10;
    cout << total << endl;
}