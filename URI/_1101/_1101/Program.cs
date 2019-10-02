using System;
using static System.Console;

namespace _1101
{
    class Program
    {
        static void Main(string[] args)
        {
            bool lever = true;
            while (lever)
            {
                string sin = ReadLine();
                int num1 = int.Parse(sin.Split()[0]);
                int num2 = int.Parse(sin.Split()[1]);

                if (num1 <= 0 || num2 <= 0)
                {
                    lever = false;
                    continue;
                }

                int max = Math.Max(num1, num2);
                int min = Math.Min(num1, num2);

                int total = 0;
                string sout = "";
                for (; min <= max; min++)
                {
                    sout = sout + min + " ";
                    total += min;
                }

                sout = sout + "Sum=" + total;
                WriteLine(sout);
            }
        }
    }
}