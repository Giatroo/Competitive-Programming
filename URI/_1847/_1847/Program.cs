using System;

namespace _1847
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] sin = Console.ReadLine().Split(' ');
            int[] t = new int[3];
            for (int i = 0; i < 3; i++)
                t[i] = Convert.ToInt32(sin[i]);

            if (
                (t[0] > t[1] && t[1] <= t[2]) ||
                (t[0] < t[1] && t[1] < t[2] && Math.Abs(t[1] - t[0]) <= Math.Abs(t[2] - t[1])) ||
                (t[0] > t[1] && t[1] > t[2] && Math.Abs(t[1] - t[0]) > Math.Abs(t[2] - t[1])) ||
                (t[0] == t[1] && t[2] > t[1])
               )
                Console.WriteLine(":)");
            else
                Console.WriteLine(":(");
        }
    }
}
