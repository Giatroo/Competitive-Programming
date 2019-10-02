using System;
using static System.Console;

namespace _1134
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = -1;
            int alco = 0, gas = 0, dies = 0;
            while(num != 4)
            {
                num = int.Parse(ReadLine());
                switch (num) {
                    case 1:
                        alco++;
                        break;
                    case 2:
                        gas++;
                        break;
                    case 3:
                        dies++;
                        break;
                }
            }
            WriteLine("MUITO OBRIGADO\nAlcool: {0}\nGasolina: {1}\nDiesel: {2}", alco, gas, dies);

        }
    }
}
