using System;

namespace _1848
{
    class Program
    {
        static void Main(string[] args)
        {
            int caw = 0;
            int sum = 0;
            while (caw < 3)
            {
                string sin = Console.ReadLine();
                if (sin == "caw caw")
                {
                    Console.WriteLine(sum);
                    sum = 0;
                    caw++;
                }
                else if (sin == "--*")
                    sum += 1;
                else if (sin == "-**")
                    sum += 3;
                else if (sin == "-*-")
                    sum += 2;
                else if (sin == "*--")
                    sum += 4;
                else if (sin == "*-*")
                    sum += 5;
                else if (sin == "**-")
                    sum += 6;
                else if (sin == "***")
                    sum += 7;
            }
        }
    }
}
