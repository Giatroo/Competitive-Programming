using System;

namespace _1959
{
    class Program
    {
        static void Main(string[] args)
        {
            string sin = Console.ReadLine();
            ulong a = ulong.Parse(sin.Split(' ')[0]);
            ulong b = ulong.Parse(sin.Split(' ')[1]);
            Console.WriteLine(a*b);
        }
    }
}
