using System;
using static System.Console;

namespace _1074
{
    class Program
    {
        static void Main(string[] args)
        {
            int j = int.Parse(ReadLine());
            string sout = "";

            for (int i = 0; i < j; i++)
            {
                int num = int.Parse(ReadLine());
                if (num == 0)
                    sout = "NULL";
                else if (num % 2 == 0) //par
                    if (num < 0)
                        sout = "EVEN NEGATIVE";
                    else
                        sout = "EVEN POSITIVE";
                else //impar
                    if (num < 0)
                    sout = "ODD NEGATIVE";
                else
                    sout = "ODD POSITIVE";
                WriteLine(sout);
            }
        }
    }
}