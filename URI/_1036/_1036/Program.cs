using System;
using static System.Console;

namespace _1036
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            double a = double.Parse(s.Split(' ')[0]);
            double b = double.Parse(s.Split(' ')[1]);
            double c = double.Parse(s.Split(' ')[2]);

            double delta = Math.Pow(b, 2) - (4 * a * c);
            if(delta < 0 || a == 0)
            {
                WriteLine("Impossivel calcular");
                Environment.Exit(0);
            }

            WriteLine("R1 = "+ ((-b + Math.Sqrt(delta)) / (2 * a)).ToString("n5").Replace(",",""));
            WriteLine("R2 = " + ((-b - Math.Sqrt(delta)) / (2 * a)).ToString("n5").Replace(",", ""));
        }
    }
}
