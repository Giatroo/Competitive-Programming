using System;
using static System.Console;

namespace _1541
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                string sin = ReadLine();
                if (int.Parse(sin[0].ToString()) == 0)
                    break;

                string[] array = sin.Split(' ');
                int A = int.Parse(array[0]);
                int B = int.Parse(array[1]);
                int Perc = int.Parse(array[2]);
                array = null;

                double Area = A * B;
                double BigArea = Area / Perc * 100;
                Console.WriteLine(Math.Truncate(Math.Sqrt(BigArea)));
            }
        }
    }
}
