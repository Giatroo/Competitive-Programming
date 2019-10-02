using System;

namespace _1043
{
    class Program
    {
        static void Main(string[] args)
        {
            string varIn = Console.ReadLine();
            float[] A = {0,0,0 };
            A[0] = float.Parse(varIn.Split(" ".ToCharArray())[0]);
            A[1] = float.Parse(varIn.Split(" ".ToCharArray())[1]);
            A[2] = float.Parse(varIn.Split(" ".ToCharArray())[2]);

            float maior= 0, menor1=0, menor2=0;

            if (A[0] > A[1] && A[0] > A[2])
            {
                maior = A[0];
                menor1 = A[1];
                menor2 = A[2];
            }
            if (A[1] > A[0] && A[1] > A[2])
            {
                maior = A[1];
                menor1 = A[0];
                menor2 = A[2];
            }
            if (A[2] > A[1] && A[2] > A[0])
            {
                maior = A[2];
                menor1 = A[1];
                menor2 = A[0];
            }

            if(maior > (menor1 + menor2)) //triangulo
            {
                Console.WriteLine("Perimetro = "+(maior+menor1+menor2).ToString("n1"));
            }
        }
    }
}
