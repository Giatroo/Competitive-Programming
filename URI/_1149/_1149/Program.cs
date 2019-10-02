using System;
using static System.Console;

namespace _1149
{
    class Program
    {
        static void Main(string[] args)
        {
            string sin = ReadLine();
            int a = int.Parse(sin.Split(' ')[0]);
            int n = int.Parse(sin.Split(' ')[sin.Split(' ').Length-1]);
            int soma = 0;
            int an = a + n;

            while(a < an)
            {
                soma += a;
                a++;
            }

            WriteLine(soma);

        }
    }
}
