#include <iostream>

using namespace std;

int main(){
    int n;
    long long anterior, atual, pontuacao, pontAtual;
    cin >> n;
    pontuacao = pontAtual = 1;
    cin >> anterior;
    for(int i = 1; i < n; i++){
        cin >> atual;
        if(atual == anterior) pontAtual++;
        else {
            if(pontAtual > pontuacao)
                pontuacao = pontAtual;
            pontAtual = 1;
        }
        anterior = atual;
    }
    if(pontAtual > pontuacao)
        pontuacao = pontAtual;
    cout << pontuacao;
}