using System;
using static System.Console;

namespace _1158
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            for (int i = 0; i < num; i++)
            {
                string sin = ReadLine();
                int num1 = int.Parse(sin.Split(' ')[0]);
                int num2 = int.Parse(sin.Split(' ')[1]);

                int soma = 0;

                if (num1 % 2 == 0)
                    num1++;

                for(int j = 0; j < num2; j++, num1+=2)
                {
                    soma += num1;
                }

                WriteLine(soma);
            }
        }
    }
}