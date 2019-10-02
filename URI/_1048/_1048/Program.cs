using System;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _1048
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            double oldSalary =double.Parse(ReadLine());
            int perc = 0;

            if (oldSalary >= 0 && oldSalary <= 400)
                perc = 15;
            else if (oldSalary <= 800)
                perc = 12;
            else if (oldSalary <= 1200)
                perc = 10;
            else if (oldSalary <= 2000)
                perc = 7;
            else
                perc = 4;

            double gain = oldSalary * perc / 100;
            double newSalary = oldSalary + gain;

            WriteLine("Novo salario: {0}\n" +
                        "Reajuste ganho: {1}\n" +
                        "Em percentual: {2} %", newSalary.ToString("n2").Replace(",",""), gain.ToString("n2"), perc);

        }
    }
}
