using System;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _1050
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            int inS = int.Parse(ReadLine());
            string outS = "";

            switch (inS)
            {
                case 61:
                    outS = "Brasilia";
                    break;
                case 71:
                    outS = "Salvador";
                    break;
                case 11:
                    outS = "Sao Paulo";
                    break;
                case 21:
                    outS = "Rio de Janeiro";
                    break;
                case 32:
                    outS = "Juiz de Fora";
                    break;
                case 19:
                    outS = "Campinas";
                    break;
                case 27:
                    outS = "Vitoria";
                    break;
                case 31:
                    outS = "Belo Horrizonte";
                    break;
                default:
                    outS = "DDD nao cadastrado";
                    break;
            }
            WriteLine(outS);
        }
    }
}
