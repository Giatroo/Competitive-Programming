using System;
using static System.Console;

namespace _1435
{
    class Program
    {
        static int[,] matriz;
        static int num = -1;
        static void Main(string[] args)
        {
            while (true)
            {
                num = int.Parse(ReadLine());
                matriz = new int[num, num];
                if (num == 0)
                    break;

                for (int i = 0; i < (num + 1) / 2; i++)
                    Preencher(i + 1, i);

                for (int i = 0; i < num; i++)
                    for (int j = 0; j < num; j++)
                    {
                        if (j == 0 && num == 1)
                            Console.WriteLine("{0,3}", matriz[i, j]);
                        else if (j == 0)
                            Console.Write("{0,3}", matriz[i, j]);
                        else if (j == num - 1 && i == num - 1)
                        {
                            Console.Write(" ");
                            Console.WriteLine("{0,3}", matriz[i, j]);
                        }
                        else if (j == num - 1)
                        {
                            Console.Write(" ");
                            Console.WriteLine("{0,3}", matriz[i, j]);
                        }
                        else
                        {
                            Console.Write(" ");
                            Console.Write("{0,3}", matriz[i, j]);
                        }
                    }
                Console.WriteLine();
            }
        }

        static void Preencher(int n, int startIndex)
        {
            for (int i = startIndex; i < num - startIndex; i++)
                for (int j = startIndex; j < num - startIndex; j++)
                    matriz[i, j] = n;
        }
    }
}
