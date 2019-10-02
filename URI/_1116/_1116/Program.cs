using System;
using static System.Console;

namespace _1116
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());

            for(int i = 0; i < num; i++)
            {
                string sin = ReadLine();
                double a = double.Parse(sin.Split(' ')[0]);
                double b = double.Parse(sin.Split(' ')[1]);

                if(b == 0)
                {
                    WriteLine("divisao impossivel");
                } else
                {
                    WriteLine((a / b).ToString("n1"));
                }

            }
        }
    }
}