using System;
using static System.Console;

namespace _1020
{
    class Program
    {
        static void Main(string[] args)
        {
            int days = int.Parse(ReadLine());
            int years = days / 365;
            days %= 365;
            int months = days / 30;
            days %= 30;
            WriteLine(years + " ano(s)");
            WriteLine(months + " mes(es)");
            WriteLine(days + " dia(s)");
        }
    }
}
