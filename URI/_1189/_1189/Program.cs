using System;
using System.Collections.Generic;
using static System.Console;

namespace _1188
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] inputs = new double[12, 12];
            string op = Console.ReadLine();

            for (int i = 0; i < 12; i++)
                for (int j = 0; j < 12; j++)
                    inputs[i, j] = double.Parse(Console.ReadLine());

            double soma = 0;
            double count = 0;
            
            for (int i = 1; i < 6; i++)
            {
                int j = 0;
                for (; j < 12; j++)
                {
                    if (j >  i - 1)
                        break;
                    soma += inputs[i, j];
                    count++;
                    
                }

            }
            for (int i = 10; i > 5; i--)
            {
                int j = 0;
                for (; j < 12; j++)
                {
                    if (j > 10 - i)
                        break;
                    soma += inputs[i, j];
                    count++;
                }

            }
            
            if (op == "S")
                Console.WriteLine(soma.ToString("n1").Replace(",", ""));
            else
                Console.WriteLine((soma / count).ToString("n1").Replace(",", ""));

        }

    }
}