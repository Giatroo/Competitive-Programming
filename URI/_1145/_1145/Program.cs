using System;
using static System.Console;

namespace _1145
{
    class Program
    {
        static void Main(string[] args)
        {
            string sin = ReadLine();
            int start = int.Parse(sin.Split(' ')[0]);
            int end = int.Parse(sin.Split(' ')[1]);
            int aux = start;
            start = 1;
            bool controlador = false;

            for (; start <= end;)
            {
                controlador = false;
                for (int i = 0; i < aux; i++)
                    if (start <= end)
                        if (i != aux - 1)
                            Write(start++ + " ");
                        else
                        {
                            WriteLine(start++);
                            controlador = true;
                        }
            }
            if (!controlador)
                WriteLine();
        }
    }
}