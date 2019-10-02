using System;
using static System.Console;

namespace _1153
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            int nReturn = 1;
            for (int i = 1; i <= num; i++)
                nReturn *= i;

            WriteLine(nReturn);
        }
    }
}
