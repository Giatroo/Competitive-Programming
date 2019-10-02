using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1827
{
    class Program
    {

        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    int num = int.Parse(Console.ReadLine());
                    int[,] matrix = new int[num, num];

                    for (int i = 0; i < num; i++)
                        matrix[i, i] = 2;

                    for (int i = num - 1; i >= 0; i--)
                        matrix[num - i - 1, i] = 3;


                    for (int i = num / 3; i < num - num / 3; i++)
                        for (int j = num / 3; j < num - num / 3; j++)
                            matrix[i, j] = 1;

                    matrix[(num - 1) / 2, (num - 1) / 2] = 4;

                    for (int i = 0; i < num; i++)
                        for (int j = 0; j < num; j++)
                        {
                            if (j != num - 1)
                                Console.Write(matrix[i, j]);
                            else
                                Console.WriteLine(matrix[i, j]);
                        }
                    Console.WriteLine();
                }
                catch
                {
                    break;
                }
            }
        }
    }
}
