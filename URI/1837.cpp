#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    int r, q;

    cin >> a >> b;

    q = a / b;
    r = a % b;
    
    if(r < 0){
        // b > 0
        // -b <= r < 0       (sum b)
        // 0 <= r + b < b    (r + b = r')
        // 0 <= r' < b

        // b < 0
        // b <= r < 0        (sub b)
        // 0 <= r - b < -b
        // 0 <= r' < -b

        if(b > 0) q--;
        else q++;

        r += abs(b);
    }

    cout << q << " " << r << endl;

    return 0;
}