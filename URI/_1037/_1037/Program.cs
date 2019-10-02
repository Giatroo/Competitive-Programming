using System;
using static System.Console;

namespace _1037
{
    class Program
    {
        static void Main(string[] args)
        {
            float d = float.Parse(ReadLine());
            if (d < 0 || d > 100) 
            {
                WriteLine("Fora de intervalo");
                Environment.Exit(1);
            }

            if (d >= 0 && d <= 25)
            {
                WriteLine("Intervalo [0,25]");
            } else if (d>25 && d<=50)
            {
                WriteLine("Intervalo (25,50]");
            } else if (d>50 && d <= 75)
            {
                WriteLine("Intervalo (50,75]");
            } else if (d>75 && d <= 100)
            {
                WriteLine("Intervalo (75,100]");
            }
        }
    }
}
