using System;

namespace _1929
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] sin = Console.ReadLine().Split(' ');
            int a = Convert.ToInt32(sin[0]), b = Convert.ToInt32(sin[1]),
                c = Convert.ToInt32(sin[2]), d = Convert.ToInt32(sin[3]);

            //abc
            if (Math.Abs(b - c) < a && a < b + c &&
                Math.Abs(a - c) < b && b < a + c &&
                Math.Abs(a - b) < c && c < a + b)
            {
                Console.WriteLine("S");
                return;
            }

            //acd
            if (Math.Abs(c - d) < a && a < c + d &&
                Math.Abs(a - d) < c && c < a + d &&
                Math.Abs(a - c) < d && d < a + c)
            {
                Console.WriteLine("S");
                return;
            }

            //abd
            if (Math.Abs(b - d) < a && a < b + d &&
                Math.Abs(a - d) < b && b < a + d &&
                Math.Abs(a - b) < d && d < a + b)
            {
                Console.WriteLine("S");
                return;
            }

            //bcd
            if (Math.Abs(c - d) < b && b < c + d &&
                Math.Abs(b - d) < c && c < b + d &&
                Math.Abs(b - c) < d && d < b + c)
            {
                Console.WriteLine("S");
                return;
            }

            Console.WriteLine("N");
        }
    }
}
