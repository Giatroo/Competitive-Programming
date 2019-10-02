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
                double.Parse(ReadLine()),
                double.Parse(ReadLine())};
            int cont = 0;
            double media = 0;


            for (int i = 0; i < intArray.Length; i++)
                if (intArray[i] > 0)
                {
                    cont++;
                    media += intArray[i];
                }

            WriteLine("{0} valores positivos", cont);

            media /= cont;

            WriteLine(media.ToString("n1"));

        }
    }
}
