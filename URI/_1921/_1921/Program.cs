using System;

namespace _1921
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = Convert.ToInt64(Console.ReadLine());
            long d = n * (n - 3) / 2;
            Console.WriteLine(n * (n - 3) / 2);
        }
    }
}
