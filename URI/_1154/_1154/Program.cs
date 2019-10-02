using System;
using static System.Console;

namespace _1154
{
    class Program
    {
        static void Main(string[] args)
        {
            float num = float.Parse(ReadLine());
            float count = 0, sum = 0;
            while (num >= 0)
            {
                sum += num;
                num = float.Parse(ReadLine());
                ++count;
            }
            WriteLine((sum / count).ToString("n2"));
        }
    }
}
