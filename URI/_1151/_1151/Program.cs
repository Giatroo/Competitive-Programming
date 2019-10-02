using System;
using static System.Console;

namespace _1151
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine()), num1 = 0, num2 = 1, aux = 0;

            for(int i = 1; i <= num; i++)
            {
                if (i != num)
                    Write(num1 + " ");
                else
                    WriteLine(num1);
                aux = num1 + num2;
                num1 = num2;
                num2 = aux;
            }
        }
    }
}
