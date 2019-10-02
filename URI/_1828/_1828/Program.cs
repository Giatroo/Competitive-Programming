using System;

namespace _1828
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 1; i <= n; i++)
            {
                string[] sin = Console.ReadLine().Split(' ');

                if (sin[0] == sin[1])
                    Console.WriteLine("Caso #" + i + ": De novo!");
                else if ((sin[0] == "tesoura" && sin[1] == "papel") ||
                    (sin[0] == "papel" && sin[1] == "pedra") ||
                    (sin[0] == "pedra" && sin[1] == "lagarto") ||
                    (sin[0] == "lagarto" && sin[1] == "Spock") ||
                    (sin[0] == "Spock" && sin[1] == "tesoura") ||
                    (sin[0] == "tesoura" && sin[1] == "lagarto") ||
                    (sin[0] == "lagarto" && sin[1] == "papel") ||
                    (sin[0] == "papel" && sin[1] == "Spock") ||
                    (sin[0] == "Spock" && sin[1] == "pedra") ||
                    (sin[0] == "pedra" && sin[1] == "tesoura"))
                    Console.WriteLine("Caso #" + i + ": Bazinga!");
                else
                    Console.WriteLine("Caso #" + i + ": Raj trapaceou!");
                
            }
        }

    }
}
