using System;
using System.Globalization;
using System.Threading;
using static System.Console;

namespace _1049
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            string in1 = ReadLine();
            string in2 = ReadLine();
            string in3 = ReadLine();
            string outS = "";

            if (in1.Equals("vertebrado"))
            {
                if (in2.Equals("ave"))
                {
                    if (in3.Equals("carnivoro"))
                    {
                        outS = "aguia";
                    } else //onivoro
                    {
                        outS = "pomba";
                    }
                } else //mamifero
                {
                    if (in3.Equals("onivoro"))
                    {
                        outS = "homem";
                    } else //herbivoro
                    {
                        outS = "vaca";
                    }
                }
            } else //invertebrado
            {
                if (in2.Equals("inseto"))
                {
                    if (in3.Equals("hematofago"))
                    {
                        outS = "pulga";
                    }
                    else //herbiforo
                    {
                        outS = "lagarta";
                    }
                }
                else //anelidio
                {
                    if (in3.Equals("hematofago"))
                    {
                        outS = "sanguessuga";
                    }
                    else //onivoro
                    {
                        outS = "minhoca";
                    }
                }
            }

            WriteLine(outS);

        }
    }
}
