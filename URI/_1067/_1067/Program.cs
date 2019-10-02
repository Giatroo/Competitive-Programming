using System;
using static System.Console;

namespace _1067
{
    class Program
    {
        static void Main(string[] args)
        {
            int max = Convert.ToInt32(ReadLine());

            for (int i = 1; i <= max; i += 2)
                WriteLine(i);
        }
    }
}
