using System;
using static System.Console;

namespace _1176
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());

            for (int j = 0; j < n; j++)
            {

                ulong num = ulong.Parse(ReadLine()), num1 = 0, num2 = 1, aux = 0;

                for (ulong i = 1; i <= num; i++)
                {
                    aux = num1 + num2;
                    num1 = num2;
                    num2 = aux;
                }


                WriteLine("Fib({0}) = {1}", num, num1);
            }
        }
    }
}
