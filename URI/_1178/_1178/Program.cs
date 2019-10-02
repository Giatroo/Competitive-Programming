using System;
using static System.Console;

namespace _1178
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal X = decimal.Parse(ReadLine());
            for(int i = 0; i < 100; i++, X /= 2)
                WriteLine("N[{0}] = {1}", i, X.ToString("n4").Replace(",",""));
        }
    }
}
