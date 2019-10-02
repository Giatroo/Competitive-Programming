using System;
using static System.Console;

namespace _1150
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(ReadLine());
            int z = int.Parse(ReadLine());
            while (z <= x)
                z = int.Parse(ReadLine());

            int resultado = 0, soma = 0;
            while(soma <= z)
            {
                soma += x++;
                ++resultado;
            }

            WriteLine(resultado);
        }
    }
}
