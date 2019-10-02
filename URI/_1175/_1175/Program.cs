using System;
using static System.Console;

namespace _1175
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[20];
            for(int i = 0; i<20; i++)
                array[i] = int.Parse(ReadLine());
            for (int i = 0, j = 19; i < 20; j--, i++)
                WriteLine("N[{0}] = {1}", i, array[j]);
        }
    }
}
