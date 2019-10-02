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
            int finalH = int.Parse(inS.Split(' ')[1]);

            if (finalH <= inicialH)
                finalH += 24;

            int totalH = finalH - inicialH;

            WriteLine("O JOGO DUROU {0} HORA(S)", totalH);

        }
    }
}
