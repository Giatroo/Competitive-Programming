using System;

namespace _1933
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] sin = Console.ReadLine().Split(' ');
            Console.WriteLine(Math.Max(Convert.ToInt32(sin[0]), Convert.ToInt32(sin[1])));
        }
    }
}
