using System;
using static System.Console;

namespace _1015
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            string[] ss = s.Split(" ".ToCharArray());
            double x1 = double.Parse(ss[0]), y1 = double.Parse(ss[1]);
            s = ReadLine();
            ss = s.Split(" ".ToCharArray());
            double x2 = double.Parse(ss[0]), y2 = double.Parse(ss[1]);

            double distance = Math.Sqrt(Math.Pow((x2-x1),2)+Math.Pow((y2 - y1),2));
            WriteLine(distance.ToString("n4").Replace(",",""));
        }
    }
}
