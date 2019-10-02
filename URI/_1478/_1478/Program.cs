using System;
using static System.Console;

namespace _1478
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

                for (int i = 0; i < num; i++)
                    for (int j = 0; j < num; j++)
                    {
                        if (i == 0)
                            matriz[i, j] = j + 1;
                        else if (j == 0)
                            matriz[i, j] = i + 1;
                        else if (i == j)
                            matriz[i, j] = 1;
                        else if (j == num - 1)
                            matriz[i, j] = num - i;
                        else if (i == num - 1)
                            matriz[i, j] = num - j;
                    }

                for (int i = 0; i < num; i++)
                    for (int j = 0; j < num; j++)
                        if (matriz[i, j] == 0)
                        {
                            if (j > i)
                                matriz[i, j] = matriz[i, j - 1] + 1;
                            else
                                matriz[i, j] = matriz[i, j - 1] - 1;
                        }
                

                //for (int i = 0; i < num; i++)
                //    Preencher(i+1);

                Apresentar();
            }
        }

        static void Preencher(int n)
        {
            int i = 0;
            while (true)
            {
                matriz[0 + i, n - 1 + i] = n;
                matriz[n - 1 + i, 0 + i] = n;
                if (n + i >= num)
                    break;
                else
                    i++;
            }
        }

        static void Apresentar()
        {
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
}
