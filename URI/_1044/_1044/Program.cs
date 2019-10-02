using System;
using static System.Console;
using System.Globalization;
using System.Threading;
namespace _1044
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            string inS = ReadLine();
            int a = int.Parse(inS.Split(' ')[0]);
            int b = int.Parse(inS.Split(' ')[1]);

            if (b % a == 0 || a % b == 0)
                WriteLine("Sao Multiplos");
            else
                WriteLine("Nao sao Multiplos");

        }
    }
}
