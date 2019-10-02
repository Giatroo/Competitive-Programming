using System;
using static System.Console;

namespace _1018
{
    class Program
    {
        static int value;
        static int rest;
        static int banknote;

        static void Main(string[] args)
        {
            value = int.Parse(ReadLine());
            WriteLine(value);
            Method(100);
            Method(50);
            Method(20);
            Method(10);
            Method(5);
            Method(2);
            Method(1);
        }

        static void Method(int i)
        {
            rest = value % i;
            banknote = value / i;
            value -= (banknote * i);
            WriteLine(banknote + " nota(s) de R$ " + double.Parse(i.ToString()).ToString("n2").Replace(".",","));
        }
    }
}
