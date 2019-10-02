using System;

namespace _1957
{
    class Program
    {
        static void Main(string[] args)
        {
            long intValue = long.Parse(Console.ReadLine());
            string hexValue = intValue.ToString("X");
            Console.WriteLine(hexValue);
        }
    }
}