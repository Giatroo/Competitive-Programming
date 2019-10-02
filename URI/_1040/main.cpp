#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double n1, n2, n3, n4;
    cin >> n1; cin >> n2; cin >> n3; cin >> n4;
    double avg = (n1*2 + n2*3 + n3*4 + n4) / 10;
    cout << "Media: " << fixed << setprecision(1) << avg << endl;
    if(avg >= 7)
        cout << "Aluno aprovado." << endl;
    else if(avg < 5)
        cout << "Aluno reprovado." << endl;
    else
    {
        cout << "Aluno em exame." << endl;
        double ne;
        cin >> ne;
        cout << "Nota do exame: " << ne << endl;
        avg = (avg + ne)/2;
        if(avg >=5)
            cout << "Aluno aprovado." << endl;
        else
            cout << "Aluno reprovado." << endl;
        cout << "Media final: " << avg << endl;
    }
    return 0;
}
