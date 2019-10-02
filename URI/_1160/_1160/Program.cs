using System;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _1160
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            int T = int.Parse(ReadLine());

            for(int i = 0; i < T; i++)
            {

                string[] sin = ReadLine().Split(' ');

                int PA = int.Parse(sin[0]), PB = int.Parse(sin[1]); //num
                double GA = double.Parse(sin[2]), GB = double.Parse(sin[3]); //percentual


                //100 * 2,5 / 100 = 

                int j = 0;
                for (; PA <= PB; PA += (int) (PA * GA / 100), PB += (int) (PB * GB / 100), j++) ;

                if (j > 100)
                    WriteLine("Mais de 1 seculo.");
                else
                    WriteLine("{0} anos.", j);
                
            }

        }
    }
}
