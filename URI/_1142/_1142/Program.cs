using System;
using static System.Console;

namespace _1142
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            int count = 1;
            for (int i = 1; i <= num; i++)
            {
                string sin = "";
                for (int j = 0; j < 4; j++, count++)
                {
                    if (count % 4 == 0)
                        sin = sin + "PUM";
                    else
                        sin = sin + count + " ";

                }
                WriteLine(sin);
            }

        }
    }
}
