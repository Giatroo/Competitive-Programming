using System;
using static System.Console;
using System.Globalization;
using System.Threading;

namespace _1046
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            string inS = ReadLine();
            int inicialH = int.Parse(inS.Split(' ')[0]);
            int inicialM = int.Parse(inS.Split(' ')[1]);
            int finalH = int.Parse(inS.Split(' ')[2]);
            int finalM = int.Parse(inS.Split(' ')[3]);

            if (finalH <= inicialH)
                finalH += 24;

            int totalH = finalH - inicialH;

            if (finalM <= inicialM)
            {
                finalM += 60;
                totalH--;
            }

            int totalM = finalM - inicialM;

            if (totalM == 60)
            {
                totalH++;
                totalM = 0;
            }

            WriteLine("O JOGO DUROU {0} HORA(S) E {1} MINUTO(S)", totalH, totalM);

        }
    }
}
