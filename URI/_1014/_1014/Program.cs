using System;
using static System.Console;

namespace _1014
{
    class Program
    {
        static void Main(string[] args)
        {
            int distance = int.Parse(ReadLine());
            double liters = double.Parse(ReadLine());
            double value = distance / liters;
            WriteLine(value.ToString("n3").Replace(",", "") + " km/l");
        }
    }
}
