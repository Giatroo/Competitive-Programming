using System;
using static System.Console;

namespace _1117
{
    class Program
    {
        static void Main(string[] args)
        {
            media();
            int i = 0;
            while (true)
            {
                WriteLine("novo calculo (1-sim 2-nao)");
                int num = int.Parse(ReadLine());
                if (num == 1)
                    media();
                else if (num == 2)
                    i = -1;

                if (i == -1)
                    break;
            }
        }

        static void media()
        {
            int num = 0;
            double total = 0;
            while (true)
            {
                double nota = double.Parse(ReadLine());
                if (0 <= nota && nota <= 10)
                {
                    num++;
                    total += nota;
                }
                else
                {
                    WriteLine("nota invalida");
                }
                if (num == 2)
                    break;
            }
            total = total / 2;
            WriteLine("media = " + total.ToString("n2"));
        }
    }
}