#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, so;
    int mag;

    cin >> s;
    if (s[0] == '-')
    {
        so += '-';
        s.erase(0, 1);
    }
    else
    {
        so += '+';
        if (s[0] == '+')
            s.erase(0, 1);
    }

    bool hasDot = false;
    int i, dotPos;
    for (i = 0; i < s.size() && !hasDot; i++)
        hasDot = (s[i] == '.');

    if (!hasDot)
    {
        so += s[0];
        so += '.';
        s.erase(0, 1);
        for (i = 0; i < 3; i++)
        {
            if (i < s.size())
                so += s[i];
            else
                so += '0';
        }

        if (i < s.size())
        {
            if (i + 1 < s.size())
            {
                if (s[i + 1] <= '9' && '5' <= s[i + 1])
                {
                    if (s[i] != '9')
                    {
                        so += (s[i] + 1);
                    }
                    else
                        so += '0';
                }
                else
                {
                    so += s[i];
                }
            }
            else
            {
                so += s[i];
            }
        }
        else
        {
            so += '0';
        }

        so += "E+";
        if (s.size() < 10)
            so += '0';
        so += to_string(s.size());
    }
    else
    {
        int msd = 0;
        dotPos = i - 1;
        for (i = 0; i < s.size() && (s[i] == '0' || s[i] == '.'); i++)
            ;
        if (i == s.size())
        {
            cout << so[0];
            cout << "0.0000E+00\n";
            return 0;
        }
        msd = i;
        mag = dotPos - msd;
        if (mag > 0)
            mag--;

        so += s[msd];
        so += '.';
        s.erase(dotPos, 1);
        if (dotPos < msd)
            msd--;
        for (i = 0; i < 3; i++)
        {
            if (msd + 1 + i < s.size())
                so += s[msd + 1 + i];
            else
                so += '0';
        }
        if (msd + 1 + i < s.size()) //arredondar
        {
            if (msd + 2 + i < s.size())
            {
                if (s[msd + 2 + i] <= '9' && s[msd + 2 + i] >= '5')
                {
                    if (s[msd + 1 + i] != '9')
                        so += (s[msd + 1 + i] + 1);
                    else
                        so += '0';
                }
                else
                    so += s[msd + 1 + i];
            }
            else
                so += s[msd + 1 + i];
        }
        else
            so += '0';
        //fim arredondar

        so += 'E';
        if (mag >= 0)
            so += '+';
        else
            so += '-';
        if (-9 <= mag && mag <= 9)
            so += "0";
        so += to_string(abs(mag));
    }

    cout << so << endl;

    return 0;
}