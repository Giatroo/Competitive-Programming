using System;
using static System.Console;

namespace _1042
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            int a = int.Parse(s.Split(' ')[0]);
            int b = int.Parse(s.Split(' ')[1]);
            int c = int.Parse(s.Split(' ')[2]);
            int aux;
            bool control;

            int[] nuns = { a, b, c };

            for (int i = 0; i < nuns.Length; i++) 
            {
                for (int j = 0; j < nuns.Length - 1; j++)
                {
                    if(nuns[j] > nuns[j + 1])
                    {
                        aux = nuns[j];
                        nuns[j] = nuns[j + 1];
                        nuns[j + 1] = aux;
                    }
                }
            }

            for(int i = 0; i<nuns.Length; i++){
                Console.WriteLine(nuns[i]);
            }
            Console.WriteLine();
            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(c);
        }
    }
}
