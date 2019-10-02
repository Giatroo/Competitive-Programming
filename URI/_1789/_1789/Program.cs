using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1789
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    int num = int.Parse(Console.ReadLine());
                    string[] sin = Console.ReadLine().Split(' ');
                    int[] slugs = new int[num];

                    int bestSlug = default(int);
                    int classification = 0;

                    for (int i = 0; i < num; i++)
                    {
                        slugs[i] = int.Parse(sin[i]);

                        if (i == 0 || slugs[i] > bestSlug)
                            bestSlug = slugs[i];
                    }

                    if (bestSlug < 10)
                        classification = 1;
                    else if (bestSlug >= 20)
                        classification = 3;
                    else
                        classification = 2;

                    Console.WriteLine(classification);
                }
                catch
                {
                    break;
                }
            }
        }
    }
}
