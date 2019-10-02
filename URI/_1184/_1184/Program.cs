using System;
using System.Collections.Generic;
using static System.Console;

namespace _1183
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
           
            for (int j = 0; j < 12; j++)
            {
                int i = j + 1;
                for (; i < 12; i++)
                {
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