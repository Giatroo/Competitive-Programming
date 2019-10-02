using System;
using System.Collections.Generic;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _2533
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            int num = int.Parse(ReadLine());

            int SM = 0;
            int SC = 0;

            for (int i = 1; i <= num; i++)
            {
                string[] sin = ReadLine().Split(' ');
                int Ni = int.Parse(sin[0]), Ci = int.Parse(sin[1]);

                SM += Ni * Ci;
                SC += Ci;
            }

            double R = ((double) SM / (SC * 100));
            WriteLine(R.ToString("n4"));
        }
    }
}
