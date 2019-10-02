using System;
using static System.Console;

namespace _1534
{
    class Program
    {
        static int[,] matriz;
        static int num = -1;
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    num = int.Parse(ReadLine());
                    matriz = new int[num, num];

                    Preencher3();
                    Preencher1();
                    Preencher2();

                    Apresentar();
                }
                catch { break; }
            }
        }

        static void Preencher3()
        {
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++)
                    matriz[i, j] = 3;
        }
        static void Preencher1()
        {
            for (int i = 0; i < num; i++)
                matriz[i, i] = 1;
        }
        static void Preencher2()
        {
            for (int i = 0; i < num; i++)
                matriz[num-i-1, i] = 2;
        }

        static void Apresentar()
        {
            for (int i = 0; i < num; i++)
                for (int j = 0; j < num; j++)
                    if (j != num - 1)
                        Write(matriz[i, j]);
                    else
                        WriteLine(matriz[i, j]);
        }
    }
}