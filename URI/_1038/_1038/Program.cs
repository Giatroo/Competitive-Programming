using System;
using static System.Console;

namespace _1038
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] prices =
            {
                4, 4.5, 5, 2, 1.5
            };
            string s = ReadLine();
            int id = int.Parse(s.Split(' ')[0]) - 1;
            int times = int.Parse(s.Split(' ')[1]);

            WriteLine("Total: R$ " + (prices[id] * times).ToString("n2").Replace(",",""));
        }
    }
}
