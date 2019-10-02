using System;
using static System.Console;

namespace _1098
{
    class Program
    {
        static void Main(string[] args)
        {
            
            for (double i = 0; i < 2; i += 0.2)
            {
                int num = 0;
                for (double j = 1+i; 3 > num; j++, num++)
                    WriteLine("I={0} J={1}", i, j);
            }
        }
    }
}