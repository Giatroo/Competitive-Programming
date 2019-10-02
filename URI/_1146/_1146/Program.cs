using System;
using static System.Console;

namespace _1146
{
    class Program
    {
        static void Main(string[] args)
        {
            ushort num = 1;
            while(num != 0)
            {
                num = ushort.Parse(ReadLine());
                for (int i = 1; i <= num; i++)
                    if (i == num)
                        WriteLine(i);
                    else
                        Write(i + " ");
            }
        }
    }
}
