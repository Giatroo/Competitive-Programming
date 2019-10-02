using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1564
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
                    if(num == 0)
                        Console.WriteLine("vai ter copa!");
                    else
                        Console.WriteLine("vai ter duas!");
                } catch
                {
                    break;
                }
            }
        }
    }
}
