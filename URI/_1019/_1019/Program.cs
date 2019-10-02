using System;
using static System.Console;

namespace _1019
{
    class Program
    {
        static void Main(string[] args)
        {
            int time = int.Parse(ReadLine()); //secods
            int hours, minutes, seconds;
            hours = time / 3600;
            minutes = (time % 3600) / 60;
            seconds = time % 60;
            WriteLine(hours + ":" + minutes + ":" + seconds);
        }
    }
}
