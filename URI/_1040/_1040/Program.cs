using System;

namespace _1040
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] ss = s.Split(" ".ToCharArray());
            double n1 = double.Parse(ss[0]);
            double n2 = double.Parse(ss[1]);
            double n3 = double.Parse(ss[2]);
            double n4 = double.Parse(ss[3]);

            double average = (((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4)) / 10);
            s = average.ToString("n2").Remove(3);
            average = double.Parse(s);
            Console.WriteLine("Media: " + s);
            if (average >= 7)
            {
                Console.WriteLine("Aluno aprovado.");
            } else if (average < 5)
            {
                Console.WriteLine("Aluno reprovado.");
            } else if (average >= 5 && average <= 6.9)
            {
                Console.WriteLine("Aluno em exame.");
                s = Console.ReadLine();
                double aux = double.Parse(s);
                Console.WriteLine("Nota do exame: " +aux.ToString("n1"));
                average = ((average + aux) / 2);
                if(average >= 5)
                {
                    Console.WriteLine("Aluno aprovado.");
                } else
                {
                    Console.WriteLine("Aluno reprovado.");
                }
                Console.WriteLine("Media final: "+average.ToString("n1"));
            }
        }
    }
}