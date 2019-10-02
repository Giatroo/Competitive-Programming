using System;
using static System.Console;

namespace _1132
{
    class Program
    {
        static void Main(string[] args)
        {
            int soma = 0;
            int x = int.Parse(ReadLine());
            int y = int.Parse(ReadLine());

            int max = Math.Max(x, y);
            int min = Math.Min(x, y);

            for (; min <= max; min++)
            {
                if (min % 13 != 0)
                    soma += min;
            }
            WriteLine(soma);
        }
    }
}