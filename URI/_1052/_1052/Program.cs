using System;
using static System.Console;

namespace _1052
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            string outS = "";

            switch (num)
            {
                case 1:
                    outS = "January";
                    break;
                case 2:
                    outS = "February";
                    break;
                case 3:
                    outS = "March";
                    break;
                case 4:
                    outS = "April";
                    break;
                case 5:
                    outS = "May";
                    break;
                case 6:
                    outS = "June";
                    break;
                case 7:
                    outS = "July";
                    break;
                case 8:
                    outS = "August";
                    break;
                case 9:
                    outS = "September";
                    break;
                case 10:
                    outS = "October";
                    break;
                case 11:
                    outS = "November";
                    break;
                case 12:
                    outS = "December";
                    break;
            }

            WriteLine(outS);
        }
    }
}
