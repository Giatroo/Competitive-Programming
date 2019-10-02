using System;
using static System.Console;

namespace _1075
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());

            for (int i = 2; i < 10000; i++)
                if (i % num == 2)
                    WriteLine(i);
        }
    }
}