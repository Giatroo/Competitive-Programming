using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1557
{
    class Program
    {

        static int[,] matrix;

        static void Main(string[] args)
        {
            while (true)
            {
                int n = int.Parse(Console.ReadLine());
                if (n == 0) break;
                matrix = new int[n, n];

                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        matrix[i, j] = int.Parse(Math.Pow(2, i+j).ToString());

                Apresentar(n);
            }
        }

        static void Apresentar(int n)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if (j == 0 && n == 1)
                        Console.WriteLine("{0,3}", matrix[i, j]);
                    else if (j == 0)
                        Console.Write("{0,3}", matrix[i, j]);
                    else if (j == n - 1 && i == n - 1)
                    {
                        Console.Write(" ");
                        Console.WriteLine("{0,3}", matrix[i, j]);
                    }
                    else if (j == n - 1)
                    {
                        Console.Write(" ");
                        Console.WriteLine("{0,3}", matrix[i, j]);
                    }
                    else
                    {
                        Console.Write(" ");
                        Console.Write("{0,3}", matrix[i, j]);
                    }
                }
            Console.WriteLine();
        }
    }
}
