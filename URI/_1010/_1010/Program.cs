using static System.Console;

namespace _1010
{
    class Program
    {
        static void Main(string[] args)
        {
            int id1, id2, vezes1, vezes2;
            float valor1, valor2;
            string s1 = ReadLine();
            string[] s11 = s1.Split(" ".ToCharArray());
            id1 = int.Parse(s11[0]);
            vezes1 = int.Parse(s11[1]);
            valor1 = float.Parse(s11[2]);

            string s2 = ReadLine();
            string[] s12 = s2.Split(" ".ToCharArray());
            id2 = int.Parse(s12[0]);
            vezes2 = int.Parse(s12[1]);
            valor2 = float.Parse(s12[2]);

            float total = (valor1 * vezes1) + (valor2 * vezes2);

            WriteLine("VALOR A PAGAR: R$ "+total.ToString("n2").Replace(",",""));
        }

    }
}
