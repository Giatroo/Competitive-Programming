using System;
using static System.Console;

namespace _1133
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(ReadLine());
            int y = int.Parse(ReadLine());

            int max = Math.Max(x, y);
            int min = Math.Min(x, y);

            for (; min < max;)
            {
                min++;
                if (min % 5 == 3 || min % 5 == 2)
                    WriteLine(min);
            }

        }
    }
}
