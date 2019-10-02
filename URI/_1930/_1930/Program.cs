using System;

namespace _1930
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] sin = Console.ReadLine().Split(' ');
            int sum = -3;
            for (int i = 0; i < sin.Length; i++)
                sum += Convert.ToInt32(sin[i]);
            Console.WriteLine(sum);
        }
    }
}
