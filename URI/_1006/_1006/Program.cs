using static System.Console;


namespace _1006
{
    class Program
    {
        static void Main(string[] args)
        {
            double media = ((double.Parse(ReadLine()) * 2) + (double.Parse(ReadLine()) * 3) + (double.Parse(ReadLine()) * 5));
            WriteLine("MEDIA = " + (media / 10).ToString("n1").Replace(",", ""));
        }
    }
}
