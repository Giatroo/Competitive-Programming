using System;
using static System.Console;

namespace _1117
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 0;
            double total = 0;
            while (true)
            {
                double nota = double.Parse(ReadLine());
                if(0 <= nota && nota <= 10)
                {
                    num++;
                    total += nota;
                } else
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