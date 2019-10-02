using System;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _1051
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            double salary = double.Parse(ReadLine());
            string outS = "";

            if (salary <= 2000)
                outS = "Isento";
            else
            {
                if (salary <= 3000)
                {
                    double first = salary - 2000;
                    first = first * 8 / 100;
                    outS = "R$ " + first.ToString("n2");
                } else if (salary <= 4500)
                {
                    double first = salary - 3000;
                    double second = salary - first - 2000;
                    first = first * 18 / 100;
                    second = second * 8 / 100;
                    outS = "R$ " + (first + second).ToString("n2");
                } else
                {
                    double first = salary - 4500;
                    double second = salary - first - 3000;
                    double th = salary - first - second - 2000;
                    first = first * 28 / 100;
                    second = second * 18 / 100;
                    th = th * 8 / 100;
                    outS = "R$ " + (first + second + th).ToString("n2").Replace(",","");
                }

            }


            WriteLine(outS);
        }
    }
}
