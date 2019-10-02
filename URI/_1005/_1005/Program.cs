using static System.Console;


namespace _1005
{
    class Program
    {
        static void Main(string[] args)
        {
            double media = ((double.Parse(ReadLine())*3.5)+(double.Parse(ReadLine())*7.5));
            WriteLine("MEDIA = "+(media/11).ToString("n5").Replace(",",""));
        }
    }
}
