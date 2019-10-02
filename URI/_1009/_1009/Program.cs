using static System.Console;

namespace _1009
{
    class Program
    {
        static void Main(string[] args)
        {
            ReadLine();
            WriteLine("TOTAL = R$ "+((double.Parse(ReadLine()))+(double.Parse(ReadLine())*0.15)).ToString("n2").Replace(",",""));
        }
    }
}
