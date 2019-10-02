#include <iostream>

using namespace std;

void grenal();
void finalization();
int vicInter = 0, vicGremio = 0, draw = 0, qnt = 0;

int main()
{
    grenal();
    return 0;
}

void grenal()
{
    int inter, gremio;
    cin >> inter; cin >> gremio;
    if(inter == gremio)
        draw++;
    else if(inter > gremio)
        vicInter++;
    else
        vicGremio++;
    qnt++;
    cout << "Novo grenal (1-sim 2-nao)" << endl;
    int a;
    cin >> a;
    if(a == 1)
        grenal();
    else
        finalization();
}

void finalization()
{
    cout << qnt << " grenais\nInter:" << vicInter << "\nGremio:" << vicGremio << "\nEmpates:" << draw << endl;
    if(vicInter == vicGremio)
        cout << "Nao houve vencedor" << endl;
    else if(vicInter > vicGremio)
        cout << "Inter venceu mais" << endl;
    else
        cout << "Gremio venceu mais" << endl;
}
