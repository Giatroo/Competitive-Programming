#include <iostream>

using namespace std;

int main()
{
    int starth, endh, lastedh, startm, endm, lastedm;
    cin >> starth; cin >> startm; cin >> endh; cin >> endm;
    /*if(starth == endh && startm == endm)
    {
        lastedh = 24;
        lastedm = 0;
    } else if(starth == endh)
    {
        if(startm < endm)
        {
            lastedh = 0;
            lastedm = endm - startm;
        } else if(startm > endm)
        {
            lastedh = 23;
            lastedm = 60-startm+endm;
        }
    } else if(starth < endh){
        if(startm == endm)
        {
            lastedm = 0;
            lastedh = endh - starth;
        } else if(startm < endm)
        {
            lastedh = endh - starth;
            lastedm = endm - startm;
        } else if( startm > endm){
            lastedh = endh - starth - 1;
            lastedm = 60-(startm-endm);
        }
    } else if(starth > endh)
    {
        if(startm == endm)
        {
            lastedm = 0;
            lastedh = 24-(starth-endh);
        } else if(startm < endm)
        {
            lastedm = endm - startm;
            lastedh = 24-(starth-endh);
        } else if(startm > endm)
        {
            lastedh = 24-(starth-endh)-1;
            lastedm = 60-(startm-endm);
        }
    }*/

    int startmin, endmin, lastedmin;
    startmin = starth * 60 + startm;
    //cout << "startmin " << startmin << endl;
    endmin = endh * 60 + endm;
    //cout << "endmin " << endmin << endl;
    lastedmin = endmin - startmin;
    if(lastedmin <= 0)
        lastedmin += 1440; //24 * 60 (a day in minutes)
    //cout << "lastedmin " << lastedmin << endl;
    lastedh = lastedmin / 60;
    lastedmin %= 60;
    lastedm = lastedmin;

    cout << "O JOGO DUROU " << lastedh << " HORA(S) E " << lastedm << " MINUTO(S)" << endl;
    return 0;
}
