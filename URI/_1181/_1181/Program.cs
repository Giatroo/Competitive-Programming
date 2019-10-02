using System;

class URI
{

    static void Main(string[] args)
    {

        double[,] inputs = new double[12, 12];

        int inputLine = int.Parse(Console.ReadLine());
        string op = Console.ReadLine();

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                inputs[i, j] = double.Parse(Console.ReadLine());

        double soma = 0;

        for (int i = 0; i < 12; i++)
            soma += inputs[i, inputLine];

        if (op == "S")
            Console.WriteLine(soma.ToString("n1").Replace(",", ""));
        else
            Console.WriteLine((soma / 12).ToString("n1").Replace(",", ""));

    }

}