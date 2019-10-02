using System;
using static System.Console;

namespace _1078
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());

            for (int i = 1; i <= 10; i++)
                WriteLine("{0} x {1} = {2}", i, num, num*i);
        }
    }
}