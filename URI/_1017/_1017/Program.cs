using System;
using static System.Console;

namespace _1017
{
    class Program
    {
        static void Main(string[] args)
        {
            int time = int.Parse(ReadLine());
            int speed = int.Parse(ReadLine());
            int distance = time * speed;
            WriteLine((distance / 12.0).ToString("n3").Replace(",", ""));
        }
    }
}
