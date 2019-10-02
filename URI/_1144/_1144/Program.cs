using System;
using static System.Console;

namespace _1144
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());


            for (int i = 1; i <= N; i++)
            {
                WriteLine("{0} {1} {2}", i, i * i, i * i * i);
                WriteLine("{0} {1} {2}", i, (i * i)+1, (i * i * i)+1);
            }

        }
    }
}
