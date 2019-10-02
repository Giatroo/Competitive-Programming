using System;
using static System.Console;

namespace _1157
{
    class Program
    {
        static void Main(string[] args)
        {
            short num = short.Parse(ReadLine());
            for(int i = 1; i <= num; i++)
            {
                if (num % i == 0)
                    WriteLine(i);
            }
        }
    }
}
