using System;
using static System.Console;

namespace _1073
{
    class Program
    {
        static void Main(string[] args)
        {
            int final = int.Parse(ReadLine());

            for (int i = 2; i <= final; i += 2)
                WriteLine("{0}^2 = {1}", i, Math.Pow(i,2));
        }
    }
}