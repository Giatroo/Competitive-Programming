using static System.Console;

namespace _1008
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("NUMBER = "+ReadLine());
            WriteLine("SALARY = U$ "+(int.Parse(ReadLine())*double.Parse(ReadLine())).ToString("n2").Replace(",",""));
        }
    }
}
