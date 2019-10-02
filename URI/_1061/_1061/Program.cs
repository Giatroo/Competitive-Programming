using System;
using static System.Console;
using System.Globalization;
using System.Threading;

namespace _1061
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            //in
            int diaI = int.Parse(ReadLine().Substring(3));
            string s1 = ReadLine();
            int horaI = s1[0] + s1[1];
            int minI = s1[5] + s1[6];
            int secI = s1[10] + s1[11];
            int diaF = int.Parse(ReadLine().Substring(3));
            string s2 = ReadLine();
            int horaF = s2[0] + s2[1];
            int minF = s2[5] + s2[6];
            int secF = s2[10] + s2[11];
            int diaT = 0, horaT = 0, minT = 0, secT = 0;

            //proc
            //sec
            if (secF < secI)
            {
                secF += 60;
                minF--;
            }
            secT = secF - secI;
            //min
            if (minF < minI)
            {
                minF += 60;
                horaF--;
            }
            minT = minF - minI;
            //horas
            if(horaF < horaI)
            {
                horaF += 24;
                diaF--;
            }
            horaT = horaF - horaI;
            //dia
            diaT = diaF - diaI;

            //out
            WriteLine("{0} dia(s)\n{1} hora(s)\n{2} minuto(s)\n{3} segundo(s)", diaT, horaT, minT, secT);

        }
    }
}