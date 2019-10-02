using System;

namespace _1914
{
    class Program
    {
        static void Main(string[] args)
        {
            int QT = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < QT; i++)
            {
                string[] sin = Console.ReadLine().Split(' ');
                string[] sin1 = Console.ReadLine().Split(' ');
                int n1 = int.Parse(sin1[0]), n2 = int.Parse(sin1[1]);

                if(sin[1] == "PAR")
                {
                    if((n1 + n2) % 2 == 0)
                        Console.WriteLine(sin[0]);
                    else
                        Console.WriteLine(sin[2]);
                } else
                {
                    if ((n1 + n2) % 2 != 0)
                        Console.WriteLine(sin[0]);
                    else
                        Console.WriteLine(sin[2]);
                }
            }
        }
    }
}

