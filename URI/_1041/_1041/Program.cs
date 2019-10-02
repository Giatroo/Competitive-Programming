using System;
using static System.Console;

namespace _1041
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            double x = double.Parse(s.Split(' ')[0]);
            double y = double.Parse(s.Split(' ')[1]);
            if (x == 0 && y == 0)
            {

                s = "Origem";
            }
            else if (x == 0)
            {
                s = "Eixo X";
            }
            else if (y == 0)
            {
                s = "Eixo Y";
            }
            else if (x > 0)
                if (y > 0)
                {
                    s = "Q1";
                }
                else
                {
                    s = "Q4";
                }
            else
            {
                if (y > 0)
                {
                    s = "Q2";
                }
                else
                {
                    s = "Q3";
                }
            }
            WriteLine(s);
        }
    }
}