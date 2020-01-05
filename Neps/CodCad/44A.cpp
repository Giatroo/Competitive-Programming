#include <bits/stdc++.h>
#define id second.second
#define b second.first
#define p first.second
#define o first.first
#define quad pair<pair<int, int>, pair<int,int>>

using namespace std;

vector<quad> v;

bool cmp(quad p1, quad p2){
    if(p1.o != p2.o) return p1.o > p2.o;
    if(p1.p != p2.p) return p1.p > p2.p;
    if(p1.b != p2.b) return p1.b > p2.b;
    if(p1.o == p2.o && p1.p == p2.p && p1.b == p2.b) return p1.id < p2.id;
}


int main()
{
    int N, M, aux;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        v.push_back(make_pair(make_pair(0, 0), make_pair(0, i + 1)));

    for(int i = 0; i < M; i++){
            cin >> aux;
            aux--;
            v[aux].o += 1;

            cin >> aux;
            aux--;
            v[aux].p += 1;

            cin >> aux;
            aux--;
            v[aux].b += 1;
    }

    /*cout << endl;
    for (int i = 0; i < N; i++)
        cout << v[i].id << " " << v[i].o << " " << v[i].p << " " << v[i].b << endl;*/
    

    sort(v.begin(), v.end(), cmp);

    /*cout << endl;
     for (int i = 0; i < N; i++)
        cout << v[i].id << " " << v[i].o << " " << v[i].p << " " << v[i].b << endl;

    cout << endl;*/
    for (int i = 0; i < N; i++)
        cout << v[i].id << " ";
    cout << endl;
    
    return 0;
}