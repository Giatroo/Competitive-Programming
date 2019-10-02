using System;
using static System.Console;

namespace _1173
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            for(int i = 0; i < 10; i++)
            {
                WriteLine("N[{0}] = {1}", i, num);
                num *= 2;
            }
        }
    }
}
