#include <bits/stdc++.h>
typedef long long int ll;
#define fora(i, n) for(ll i = 0; i < n; i++)
#define forai(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = n-1; i >= 0; i--)
#define fordi(i, n) for(ll i = n; i >= 0; i--)
#define f first
#define s second

using namespace std;

ll min(ll a, ll b)
{
  return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
  return (a > b) ? a : b;
}

typedef pair<ll, string> Jogador;
typedef vector<Jogador> Time;

ll N, T;
ll a;
string s;
vector<Jogador> jogadores;
vector<Time> times;
ll t;

bool sortNome(Jogador j1, Jogador j2)
{
  return j1.s < j2.s;
}

int main(int argc, char const *argv[]) {
  cin >> N >> T;

  times.resize(T);

  fora(i, N)
  {
    cin >> s >> a;
    jogadores.push_back(make_pair(a, s));
  }

  sort(jogadores.begin(), jogadores.end());

  t = 0;
  fora(i, N)
  {
    times[t++].push_back(jogadores.back());
    jogadores.pop_back();
    t %= T;
  }


  fora(i, T)
  {
    cout << "Time " << i+1 << endl;
    sort(times[i].begin(), times[i].end(), sortNome);
    fora(j, times[i].size())
      cout << times[i][j].s << endl;
      cout << endl;
  }

  return 0;
}
