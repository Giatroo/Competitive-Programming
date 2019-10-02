using System;
using static System.Console;

namespace _1174
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] A = new double[100];

            for (int i = 0; i < 100; i++)
            {
                double n = double.Parse(Console.ReadLine());
                A[i] = n;
            }

            for (int i = 0; i < 100; i++)
                if (A[i] <= 10)
                    Console.WriteLine("A[" + i + "] = " + A[i].ToString("n1").Replace(",", ""));
        }
    }
}
