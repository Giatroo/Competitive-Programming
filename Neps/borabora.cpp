#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int valor;
	char naipe;
} carta;

typedef vector<carta> jogador;

deque<carta> saque;
carta descarte;
vector<jogador> jogadores;

int p, m, n;
int curj;
int sentido;
bool penalizado;

bool podeJogar(carta c)
{
	return (c.valor == descarte.valor ||
					c.naipe == descarte.naipe);
}

bool sortcards(carta a, carta b)
{
	if(a.valor == b.valor)
		return a.naipe < b.naipe;
	return a.valor < b.valor;
}

void compra(jogador *j){
	j->push_back(saque.front());
	saque.pop_front();
}

void joga(jogador *j)
{
	sort(j->begin(), j->end(), sortcards);
	int i = j->size()-1;
	bool joga = false;
	while(!joga && i >= 0){
		if(joga = podeJogar((*j)[i])){
			descarte.valor = (*j)[i].valor;
			descarte.naipe = (*j)[i].naipe;
			(*j).erase((*j).begin() + i);
			break;
		}
		i--;
	}

	if(!joga) {
		compra(j);

		if(podeJogar(*((*j).end()-1))){
			descarte.valor = ((*j).end()-1)->valor;
			descarte.naipe = ((*j).end()-1)->naipe;
			(*j).erase((*j).end()-1);
		}
	}
}

bool fimDeJogo(){
	for(int i = 0; i <= jogadores.size(); i++)
		if(!jogadores[i].size()) return true;
	return false;
}

void saca(jogador *j)
{
	carta c = saque.front();
	saque.pop_front();
	j->push_back(c);
}

void leBaralhoEDistribui()
{
	for(int i = 0; i < n; i++)
	{
		carta c;
		cin >> c.valor >> c.naipe;
		saque.push_back(c);
		c = saque.front();
	}

	for(int i = 0; i < p; i++)
		for(int j = 0; j < m; j++)
			saca(&(jogadores[i]));

	descarte = saque.front();
	saque.pop_front();
}

void imprimeMao(jogador j)
{
	for(auto x : j)
		cout << "("<<x.valor <<","<<x.naipe<< ") ";
	cout << endl;
}

void imprimeMaos()
{
	for(int i = 0; i < p; i++)
	{
		imprimeMao(jogadores[i]); cout << endl;
	}
	cout << endl;
}

int main()
{
	sentido = 1;
	curj = 0;
	cin >> p >> m >> n;
	jogadores.resize(p);
	penalizado = false;

	while(p*m*n != 0)
	{
		leBaralhoEDistribui();
		/*cout << "Inicio do jogo:\n";
		imprimeMaos();*/
		while(!fimDeJogo())
		{
			/*cout << "Jogador " << curj << endl;
			cout << "sentido = " << sentido << endl;*/
			if(descarte.valor == 12) //dama
				sentido *= -1;
			if(!penalizado && (penalizado = (descarte.valor == 7)))
			{
				saca(&(jogadores[curj]));
				saca(&(jogadores[curj]));
				goto endlbl;
			}
			if(!penalizado && (penalizado = (descarte.valor == 1)))
			{
				saca(&(jogadores[curj]));
				goto endlbl;
			}
			if(!penalizado && (penalizado = (descarte.valor == 11)))
				goto endlbl;

			penalizado = false;
			joga(&(jogadores[curj]));
			if(fimDeJogo()) break;
	endlbl:
			curj += sentido;
			curj %= p;
			if(curj < 0) curj += p;
			/*imprimeMaos();
			cout << descarte.valor << " , " << descarte.naipe << endl;
			cout << "---\n\n";
			cin >> temp;*/
		}

		cout << curj + abs(sentido) << endl;

		sentido = 1;
		curj = 0;
		cin >> p >> m >> n;
		for(auto j : jogadores)
			j.clear();
		jogadores.clear();
		jogadores.resize(p);
		saque.clear();
		penalizado = false;
	}



	return 0;
}
