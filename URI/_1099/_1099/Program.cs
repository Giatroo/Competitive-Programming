using System;
using static System.Console;

namespace _1099
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            for(int i = 0; i < num; i++)
            {
                string sin = ReadLine();
                int num1 = int.Parse(sin.Split(' ')[0]);
                int num2 = int.Parse(sin.Split(' ')[1]);

                int high = Math.Max(num1, num2);
                int low = Math.Min(num1, num2);

                int soma = 0;


                bool par = false;

                if (low % 2 == 0)
                    par = true;

                if (!par)
                {
                    low += 2;
                    for (; low < high; low += 2)
                    {
                        soma += low;
                    }
                }
                else
                {
                    low++;
                    for (; low < high; low += 2)
                        soma += low;

                }

                WriteLine(soma);
            }
        }
    }
}