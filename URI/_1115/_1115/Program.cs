using System;
using static System.Console;

namespace _1115
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string sin = ReadLine();
                int x = int.Parse(sin.Split(' ')[0]);
                int y = int.Parse(sin.Split(' ')[1]);

                if (x > 0 && y > 0)
                    WriteLine("primeiro");
                else if (x < 0 && y > 0)
                    WriteLine("segundo");
                else if (x < 0 && y < 0)
                    WriteLine("terceiro");
                else if (x > 0 && y < 0)
                    WriteLine("quarto");
                else if (x == 0 || y == 0)
                    break;
            }
        }
    }
}