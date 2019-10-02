using System;
using static System.Console;

namespace _1097
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 7;
            for (int i = 1; i < 10; i += 2, num +=2)
            {
                for (int j = num; j > num - 3; j--)
                    WriteLine("I={0} J={1}", i, j);
            }
        }
    }
}