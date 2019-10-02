using System;
using static System.Console;

namespace _1013
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            string[] array = s.Split(" ".ToCharArray());
            int a = int.Parse(array[0]), b = int.Parse(array[1]), c = int.Parse(array[2]);
            int maior = (a + b + Math.Abs(a - b)) / 2;
            maior = (maior + c + Math.Abs(maior - c)) / 2;
            WriteLine(maior + " eh o maior");
        }
    }
}
