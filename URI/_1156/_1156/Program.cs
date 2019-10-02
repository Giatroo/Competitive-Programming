using System;
using static System.Console;

namespace _1155
{
    class Program
    {
        static void Main(string[] args)
        {
            double s = 1.0;
            double x = 2.0;

            for (int i = 3; i <= 39; i += 2)
            {
                s += i / x;
                x *= 2;
            }

            Console.WriteLine(s.ToString("n2"));
        }
    }
}