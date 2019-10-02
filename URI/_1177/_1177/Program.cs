using System;
using static System.Console;

namespace _1177
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(ReadLine());
            for (int i = 0; i < 1000;)
                for (int j = 0; j < T; j++, i++)
                {
                    if (i == 1000)
                        break;
                    WriteLine("N[{0}] = {1}", i, j);
                }
        }
    }
}
