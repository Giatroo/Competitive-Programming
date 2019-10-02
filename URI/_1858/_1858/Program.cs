using System;

namespace _1858
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            int[] T = new int[N];
            string[] sin = Console.ReadLine().Split(' ');
            int menor = int.MinValue;
            int iDeMenor = 0;
            for (int i = 0; i < N; i++)
            {
                T[i] = Convert.ToInt32(sin[i]);
                if (i == 0)
                {
                    menor = T[0];
                    iDeMenor = 0;
                }
                if (T[i] < menor)
                {
                    menor = T[i];
                    iDeMenor = i;
                }
            }
            Console.WriteLine(iDeMenor + 1);
        }
    }
}
