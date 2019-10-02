using System;
using static System.Console;

namespace _1165
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());

            for (int i = 0; i < N; i++)
            {
                int X = int.Parse(ReadLine());
                int soma = 0;
                for (int j = 1; j < X; j++)
                {
                    if (X % j == 0)
                        soma += j;
                }

                if (soma == 1)
                    WriteLine("{0} eh primo", X);
                else
                    WriteLine("{0} nao eh primo", X);

            }
        }
    }
}
