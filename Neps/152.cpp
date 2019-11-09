#include <iostream>

using namespace std;

bool Mai(char c);
bool Min(char c);

string title(string F){
    if(Min(F[0]))
      F[0] += ('A' - 'a');
    for(int i = 1; i < F.size(); i++)
    {
      if(F[i-1] == ' ' && Min(F[i]))
        F[i] += ('A' - 'a');
      else if(F[i-1] != ' ' && Mai(F[i]))
        F[i] += ('a' - 'A');
    }
    return F;
}

bool Mai(char c)
{
  return ('A' <= c && c <= 'Z');
}

bool Min(char c)
{
  return ('a' <= c && c <= 'z');
}

int main(){
    string F;

    getline(cin, F);

    cout << title(F) << "\n";
}
