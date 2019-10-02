using System;
using static System.Console;

namespace _1114
{
    class Program
    {
        static void Main(string[] args)
        {
            bool lever = true;
            while(lever){
                int key = int.Parse(ReadLine());
                if (key == 2002) {
                    lever = false;
                    continue;
                }
                WriteLine("Senha Invalida");
            }
            WriteLine("Acesso Permitido");
        }
    }
}