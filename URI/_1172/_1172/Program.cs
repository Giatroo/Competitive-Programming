using System;
using static System.Console;

namespace _1172
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                int num = int.Parse(ReadLine());
                if (num <= 0)
                    num = 1;

                WriteLine("X[{0}] = {1}", i, num);
            }
        }
    }
}
