using System;

namespace _1866
{
    class Program
    {
        static void Main(string[] args)
        {
            int C = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < C; i++)
                if (Convert.ToInt32(Console.ReadLine()) % 2 == 0)
                    Console.WriteLine(0);
                else
                    Console.WriteLine(1);
        }
    }
}
