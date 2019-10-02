using System;

namespace _1002
{
    class Program
    {
        static void Main(string[] args)
        {
            double raio = double.Parse(Console.ReadLine());
            Console.WriteLine("A="+ (3.14159 * Math.Pow(raio, 2)).ToString("n4").Replace(",",""));
        }
    }
}
