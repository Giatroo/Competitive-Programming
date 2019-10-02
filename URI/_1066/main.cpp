#include <iostream>

using namespace std;

int main()
{
    int even=0, odd=0, positive=0, negative=0;
    for(int i = 0; i<5; i++){
        int n;
        cin >> n;
        if(n > 0)
            positive++;
        if(n < 0)
            negative++;
        if(n%2==0)
            even++;
        else
            odd++;
    }
    cout << even << " valor(es) par(es)\n" << odd << " valor(es) impar(es)\n" << positive << " valor(es) positivo(s)\n" << negative << " valor(es) negativo(s)\n";
    return 0;
}
