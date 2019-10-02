using System;
using static System.Console;

namespace _1131
{
    class Program
    {
        static void Main(string[] args)
        {
            int lever = -1;
            int vicGremio = 0, vicInter = 0, empates = 0, numGrenais = 0;
            while(lever != 2)
            {
                string sin = ReadLine();
                int golsInter = int.Parse(sin.Split(' ')[0]);
                int golsGremio = int.Parse(sin.Split(' ')[1]);

                if (golsInter > golsGremio)
                    vicInter++;
                else if (golsGremio > golsInter)
                    vicGremio++;
                else
                    empates++;

                numGrenais++;

                WriteLine("Novo grenal (1-sim 2-nao)");
                lever = int.Parse(ReadLine());
            }

            WriteLine(numGrenais + " grenais");
            WriteLine("Inter:"+vicInter);
            WriteLine("Gremio:" + vicGremio);
            WriteLine("Empates:"+empates);
            if (vicInter > vicGremio)
                WriteLine("Inter venceu mais");
            else if (vicInter < vicGremio)
                WriteLine("Gremio venceu mais");
            else
                WriteLine("Nao houve vencedor");
        }
    }
}