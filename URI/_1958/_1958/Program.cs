using System;

namespace _1958
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal n = decimal.Parse(Console.ReadLine());
            string sout = (n).ToString("0.0000E00");
            Console.WriteLine(sout);
        }
    }
}
