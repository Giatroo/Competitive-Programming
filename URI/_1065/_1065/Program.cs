using System;
using static System.Console;

namespace _1060
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] intArray = {
                double.Parse(ReadLine()),
                double.Parse(ReadLine()),
                double.Parse(ReadLine()),
                double.Parse(ReadLine()),
                double.Parse(ReadLine())};
            int cont = 0;


            for (int i = 0; i < intArray.Length; i++)
                if (intArray[i] % 2 == 0)
                    cont++;

            WriteLine("{0} valores pares", cont);

        }
    }
}
