using System;
using static System.Console;

namespace _1095
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 1, j = 60; j >= 0; j -= 5, i += 3)
                WriteLine("I={0} J={1}", i, j);
        }
    }
}