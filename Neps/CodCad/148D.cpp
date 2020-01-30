#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

vector< pair <int,int> > vect;

int main()
{
    int N, M, aux;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        vect.push_back(make_pair(0, i+1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> aux;
            (vect[i]).first += aux;
        }
    }
    sort(vect.begin(), vect.end());
    cout << (vect[0]).second << endl;
    cout << (vect[1]).second << endl;
    cout << (vect[2]).second << endl;
    return 0;
}