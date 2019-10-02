using System;
using static System.Console;

namespace _1079
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            for(int i = 0; i < num; i++)
            {
                string sin = ReadLine();
                WriteLine(((((2 * double.Parse(sin.Split(' ')[0])) + (3 * double.Parse(sin.Split(' ')[1])) + (5 * double.Parse(sin.Split(' ')[2]))) / 10).ToString("n1")));
            }

        }
    }
}