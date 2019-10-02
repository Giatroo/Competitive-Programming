using System;
using static System.Console;

namespace _1012
{
    class Program
    {
        static void Main(string[] args)
        {
            string entrada = ReadLine();
            string[] array = entrada.Split(" ".ToCharArray());
            double A = double.Parse(array[0]);
            double B = double.Parse(array[1]);
            double C = double.Parse(array[2]);
            double triangulo = (A * C) / 2;
            double circulo = 3.14159 * C * C;
            double trapezio = ((A + B) * C) / 2;
            double quadrado = B * B;
            double retangulo = A * B;

            WriteLine("TRIANGULO: "+triangulo.ToString("n3").Replace(",",""));
            WriteLine("CIRCULO: "+circulo.ToString("n3").Replace(",", ""));
            WriteLine("TRAPEZIO: "+trapezio.ToString("n3").Replace(",", ""));
            WriteLine("QUADRADO: "+quadrado.ToString("n3").Replace(",", ""));
            WriteLine("RETANGULO: "+retangulo.ToString("n3").Replace(",", ""));
        }
    }
}
