using System;

namespace _1865
{
    class Program
    {
        static void Main(string[] args)
        {
            int C = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < C; i++)
                if (Console.ReadLine().Split(' ')[0] == "Thor")
                    Console.WriteLine("Y");
                else
                    Console.WriteLine("N");
        }
    }
}
