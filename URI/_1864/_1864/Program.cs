using System;

namespace _1864
{
    class Program
    {
        static void Main(string[] args)
        {
            const string life = "LIFE IS NOT A PROBLEM TO BE SOLVED";
            int n = int.Parse(Console.ReadLine());
            string sout = "";
            for (int i = 0; i < n; i++)
                sout += life[i];
            
            Console.WriteLine(sout);
        }
    }
}
