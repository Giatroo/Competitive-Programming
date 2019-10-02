using System;
using static System.Console;

namespace _1080
{
    class Program
    {
        static void Main(string[] args)
        {
            int maior = 0, posicao = 0;

            for(int i = 0; i < 100;i++)
            {
                int num = int.Parse(ReadLine());
                if(num > maior)
                {
                    maior = num;
                    posicao = i+1;
                }
            }
            WriteLine(maior);
            WriteLine(posicao);
        }
    }
}