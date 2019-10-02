#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, c = 0, r = 0, s = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        int amount;
        char letter;
        cin >> amount; cin >> letter;
        switch(letter){
            case 'C':
                c += amount;
                break;
            case 'R':
                r += amount;
                break;
            case 'S':
                s += amount;
                break;
        }
    }
    int total = c + r + s;
    cout << "Total: " << total << " cobaias\n";
    cout << "Total de coelhos: " << c << endl;
    cout << "Total de ratos: " << r << endl;
    cout << "Total de sapos: " << s << endl;
    double percC = (double)c / total * 100;
    double percR = (double)r / total * 100;
    double percS = (double)s / total * 100;
    cout << "Percentual de coelhos: " << fixed << setprecision(2) << percC << " %" << endl;
    cout << "Percentual de ratos: " << fixed << setprecision(2) << percR << " %" << endl;
    cout << "Percentual de sapos: " << fixed << setprecision(2) << percS << " %" << endl;
    return 0;
}
