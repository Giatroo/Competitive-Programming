using System;
using static System.Console;

namespace _1589
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            for (int i = 0; i < num; i++)
            {
                string sin = ReadLine();
                Console.WriteLine((int.Parse(sin.Split(' ')[0]) + int.Parse(sin.Split(' ')[1])));
            }
        }
    }
}
