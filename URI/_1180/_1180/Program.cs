using System;
using System.Collections.Generic;
using static System.Console;

namespace _1180
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            string[] sin = ReadLine().Split(' ');
            List<int> array = new List<int>();

            for (int i = 0; i < num; i++)
                array.Add(int.Parse(sin[i]));

            int menor = 99999999;
            int pos = 0;

            foreach(int n in array)
            {
                if (n < menor)
                {
                    menor = n;
                    pos = array.IndexOf(n);
                }
            }

            WriteLine("Menor valor: {0}\nPosicao: {1}", menor, pos);
        }
    }
}
