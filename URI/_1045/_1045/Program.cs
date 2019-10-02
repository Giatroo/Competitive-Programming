using System;
using static System.Console;
using System.Globalization;
using System.Threading;

namespace _1045
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            string inS = ReadLine();
            double in1 = double.Parse(inS.Split(' ')[0]);
            double in2 = double.Parse(inS.Split(' ')[1]);
            double in3 = double.Parse(inS.Split(' ')[2]);
            double aux1, aux2;

            aux1 = in1;
            aux2 = in2;

            in1 = Math.Max(aux1, aux2);
            in2 = Math.Min(aux1, aux2);

            aux1 = in2;
            aux2 = in3;

            in2 = Math.Max(aux1, aux2);
            in3 = Math.Min(aux1, aux2);

            aux1 = in1;
            aux2 = in2;

            in1 = Math.Max(aux1, aux2);
            in2 = Math.Min(aux1, aux2);

            double a = in1, b = in2, c = in3;

            if (a >= (b + c))
                WriteLine("NAO FORMA TRIANGULO");
            else
            {
                if ((a * a) == ((b * b) + (c * c)))
                    WriteLine("TRIANGULO RETANGULO");
                if ((a * a) > ((b * b) + (c * c)))
                    WriteLine("TRIANGULO OBTUSANGULO");
                if ((a * a) < ((b * b) + (c * c)))
                    WriteLine("TRIANGULO ACUTANGULO");
                if (a == b && b == c && a == c)
                    WriteLine("TRIANGULO EQUILATERO");
                else if (a == b | b == c | a == c)
                    WriteLine("TRIANGULO ISOSCELES");
            }

        }
    }
}
