using System;
using static System.Console;

namespace _1035
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = ReadLine();
            string[] ss = s.Split(" ".ToCharArray());
            int A = int.Parse(ss[0]);
            int B = int.Parse(ss[1]);
            int C = int.Parse(ss[2]);
            int D = int.Parse(ss[3]);


            if (B > C && D > A && (C + D) > (A + B) && Math.Sign(C) == 1 && Math.Sign(D) == 1 && A % 2 == 0)
                Console.WriteLine("Valores aceitos");
            else
                Console.WriteLine("Valores nao aceitos");
        }
    }
}
