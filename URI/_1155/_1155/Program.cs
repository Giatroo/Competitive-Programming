using System;
using static System.Console;

namespace _1155
{
    class Program
    {
        static void Main(string[] args)
        {
            double sum = 0.0;

            for (int i = 1; i < 101; ++i)
                sum += 1.0 / i;

            WriteLine(sum.ToString("n2"));
        }
    }
}
