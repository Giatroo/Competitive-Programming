using System;
using static System.Console;

namespace _1159
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = -1;
            while (true)
            {
                num = int.Parse(ReadLine());
                if (num == 0)
                    break;

                int soma = 0;

                if (num % 2 != 0)
                    num++;

                for (int j = 0; j < 5; j++, num += 2)
                {
                    soma += num;
                }

                WriteLine(soma);

            } 
        }
    }
}
