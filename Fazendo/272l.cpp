#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define pb push_back
#define mp make_pair

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

class carta {
public:
  int num;
  char naipe;

  bool operator < (carta c1) {
    if(c1.num == num)
      return c1.naipe < naipe;
    return c1.num < num;
  }
};

vector<carta> deck;
carta atual;
int p, m, n;
int g;
int d;
int curp;

void colocaNaMesa(carta c);

int proximoJogador() {
  if (0 <= curp + d && curp + d < p)
    return curp + d;
  else if (curp + d < 0)
    return p - 1;
  else return 0;
}

class jogador {
public:
  vector<carta> mao;

  int temCarta() {
    fora(i, mao.size())
      if (mao[i].num == atual.num ||
          mao[i].naipe == atual.naipe)
        return i;
    return -1;
  }

  bool joga() {
    int card;
    sortvector(mao);
    card = temCarta();
    if(card != -1) {
      // cout << "Jogando " << mao[card].num << " " << mao[card].naipe << endl;
      colocaNaMesa(mao[card]);
      vector<carta>::iterator it;
      it = mao.begin();
      fora(i, card) it++;
      mao.erase(it);
    }
    else {
      // cout << "Comprando " << deck[g].num << " " << deck[g].naipe << endl;
      if(deck[g].num != atual.num &&
         deck[g].naipe != atual.naipe)
        mao.pb(deck[g++]);
      else {
        // cout << "Consegui jogar." << endl;
        colocaNaMesa(deck[g++]);
      }
    }
    return mao.empty();
  }

  bool maoVazia() {
    return mao.empty();
  }

  void mostraMao() {
    fora(i, mao.size())
      cout << mao[i].num << " " << mao[i].naipe << endl;
    cout << endl;
  }

};

vector<jogador> jogadores;

void colocaNaMesa(carta c) {
  atual.num = c.num;
  atual.naipe = c.naipe;
  if (atual.num == 12) //dama
    d *= -1; //inverte o jogo
  else if (atual.num == 7) //sete
  {
    //compra duas
    jogadores[proximoJogador()].mao.pb(deck[g++]);
    jogadores[proximoJogador()].mao.pb(deck[g++]);
    //pula a vez
    curp = proximoJogador();
  } else if (atual.num == 1) //as
  {
    //compra uma
    jogadores[proximoJogador()].mao.pb(deck[g++]);
    //pula a vez
    curp = proximoJogador();
  } else if (atual.num == 11) //valete
  {
    //pula a vez
    curp = proximoJogador();
  }
}

int jogadorAnterior() {
  if (0 <= curp - d && curp - d < p)
    return curp - d;
  else if (curp - d < 0)
    return p - 1;
  else return 0;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> p >> m >> n;
    while(p*m*n != 0) {
    //Leitura das cartas
    fora(i, n) {
      carta c;
      cin >> c.num >> c.naipe;
      deck.pb(c);
    }

    //Distribuindo as cartas
    g = 0;

    fora(i, p) {
      jogador jog;
      fora(j, m) {
        jog.mao.pb(deck[g++]);
      }
      jogadores.pb(jog);
    }

    // fora(i, p) {
    //   cout << "Mao do jogador " << i + 1 << endl;
    //   fora(j, m) {
    //     cout << jogadores[i].mao[j].num << " " << jogadores[i].mao[j].naipe << endl;
    //   }
    //   cout << endl;
    // }

    d = 1; //Direção por padrão é crescente
    curp = 0;
    colocaNaMesa(deck[g++]);

    //Jogando
    while (true) {
      // cout << "Jogador " << curp + 1 << endl;
      if (jogadores[curp].joga()) {
        if (atual.num != 7 && atual.num != 1 && atual.num != 11)
          cout /*<< "1Ganhador foi "*/ << curp + 1 << endl;
        else
          cout /*<< "2Ganhador foi "*/ << jogadorAnterior() + 1 << endl;
        break;
      }
      // cout << "Mao do jogador " << curp + 1 << endl;
      // jogadores[curp].mostraMao();
      // cout << "Atual: " << atual.num << " " << atual.naipe << endl;


      if (g == n + 1) break;

      curp = proximoJogador();
    }

    //Limpando todos os vectors
    deck.clear();
    fora(i, p)
      jogadores[i].mao.clear();
    jogadores.clear();
    //Lendo os novos inputs
    cin >> p >> m >> n;
  }
  return 0;
}
