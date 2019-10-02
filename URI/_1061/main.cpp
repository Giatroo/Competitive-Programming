#include <iostream>
#include <string>

using namespace std;

int main()
{
    string tresh;
    cin >> tresh;
    int sd, sh, sm, ss, ed, eh, em, es;
    cin >> sd; cin >> sh; cin >> tresh; cin >> sm; cin >> tresh; cin >> ss;
    cin >> tresh; cin >> ed; cin >> eh; cin >> tresh; cin >> em; cin >> tresh; cin >> es;

    //cout << "Day " << sd << " hour " << sh << " min " << sm << " sec " << ss << endl;
    //cout << "Day " << ed << " hour " << eh << " min " << em << " sec " << es << endl;
    int stime = 3600 * 24 * sd + 3600 * sh + 60 * sm + ss;
    int etime = 3600 * 24 * ed + 3600 * eh + 60 * em + es;
    int time = etime - stime;
    int d, h, m, s;
    d = time / (3600*24);
    time %= (3600*24);
    h = time / 3600;
    time %= 3600;
    m = time / 60;
    time %= 60;
    s = time;
    cout << d << " dia(s)\n" << h << " hora(s)\n" << m << " minuto(s)\n" << s << " segundo(s)\n";
}
