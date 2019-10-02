using System;
using System.Collections.Generic;
using static System.Console;

namespace _1164
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());

            for(int i = 0; i < N; i++)
            {
                int X = int.Parse(ReadLine());
                int soma = 0;
                for (int j = 1; j <X; j++)
                {
                    if (X % j == 0)
                        soma += j;
                }
                
                if (soma == X)
                    WriteLine("{0} eh perfeito", X);
                else
                    WriteLine("{0} nao eh perfeito", X);
            }
        }
    }
}
