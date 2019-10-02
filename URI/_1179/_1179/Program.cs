using System;
using System.Collections.Generic;
using static System.Console;

namespace _1179
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> par = new List<int>();
            List<int> impar = new List<int>();

            for (int i = 0; i < 15; i++)
            {
                int n = int.Parse(ReadLine());

                if (n % 2 == 0)
                    par.Add(n);
                else
                    impar.Add(n);

                if (par.Count == 5)
                {
                    for (int j = 0; j < 5; j++)
                        WriteLine("par[{0}] = {1}", j, par[j]);
                    par.Clear();
                }
                if (impar.Count == 5)
                {
                    for (int j = 0; j < 5; j++)
                        WriteLine("impar[{0}] = {1}", j, impar[j]);
                    impar.Clear();
                }
            }

            for(int i = 0; i < impar.Count; i++)
                WriteLine("impar[{0}] = {1}", i, impar[i]);

            for (int j = 0; j < par.Count; j++)
                WriteLine("par[{0}] = {1}", j, par[j]);
        }
    }
}
