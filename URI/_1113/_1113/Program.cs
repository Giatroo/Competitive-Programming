using System;
using static System.Console;

namespace _1113
{
    class Program
    {
        static void Main(string[] args)
        {
            bool lever = true;
            while(lever){
                string sin = ReadLine();
                string sout = "";
                int a = int.Parse(sin.Split(' ')[0]);
                int b = int.Parse(sin.Split(' ')[1]);

                if(a == b)
                {
                    lever = false;
                    continue;
                } else if (a > b)
                {
                    sout = "Decrescente";
                } else if (a < b)
                {
                    sout = "Crescente";
                }
                WriteLine(sout);
            }

        }
    }
}