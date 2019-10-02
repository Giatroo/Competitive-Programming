using System;
using static System.Console;

namespace _1094
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(ReadLine());
            int cobT = 0, cobC = 0, cobR = 0, cobS = 0;


            for(int i = 0; i< num; i++)
            {
                string sin = ReadLine();
                int cob = int.Parse(sin.Split(' ')[0]);
                switch (sin.Split(' ')[1].ToCharArray()[0])
                {
                    case 'C':
                        cobC += cob;
                        break;
                    case 'R':
                        cobR += cob;
                        break;
                    case 'S':
                        cobS += cob;
                        break;
                }
            }
            cobT = cobS + cobR + cobC;

            WriteLine("Total: " + cobT + " cobaias");
            WriteLine("Total de coelhos: " + cobC);
            WriteLine("Total de ratos: " + cobR);
            WriteLine("Total de sapos: " + cobS);

            double pC, pR, pS;
            pC = (cobC * 100.0) / cobT;
            pR = (cobR * 100.0) / cobT;
            pS = (cobS * 100.0) / cobT;

            WriteLine("Percentual de coelhos: " + pC.ToString("n2") + " %");
            WriteLine("Percentual de ratos: " + pR.ToString("n2") + " %");
            WriteLine("Percentual de sapos: " + pS.ToString("n2") + " %");
            //cobT          100%
            //cobC          pC%
            //pC * cobT = cobC * 100
            //pC = (cobC * 100) / cobT

        }
    }
}
