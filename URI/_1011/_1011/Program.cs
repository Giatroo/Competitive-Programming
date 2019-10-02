using static System.Console;
using System;

namespace _1011
{
    class Program
    {
        static void Main(string[] args)
        {
            const double PI = 3.14159;
            double raio = double.Parse(ReadLine());
            double volume = ((4 / 3.0) * PI * raio * raio * raio);
            WriteLine("VOLUME = " + volume.ToString("n3").Replace(",", ""));
        }
    }
}
