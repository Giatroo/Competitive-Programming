using System;
using static System.Console;

namespace _1021
{
    class Program
    {
        static double value;
        static double rest;
        static int banknote;
        static int coins;
        static string notesS = " nota(s) de R$ ";
        static string coinsS = " moeda(s) de R$ ";

        static void Main(string[] args)
        {
            value = double.Parse(ReadLine());
            WriteLine("NOTAS:");
            MethodNotes(100, notesS);
            MethodNotes(50, notesS);
            MethodNotes(20, notesS);
            MethodNotes(10, notesS);
            MethodNotes(5, notesS);
            MethodNotes(2, notesS);
            WriteLine("MOEDAS:");
            MethodNotes(1, coinsS);

            string aux = value.ToString("n2").Remove(0,2);
            value = int.Parse(aux);

            MethodCoins(50, coinsS);
            MethodCoins(25, coinsS);
            MethodCoins(10, coinsS);
            MethodCoins(05, coinsS);
            MethodCoins(01, coinsS);
        }

        static void MethodNotes(int i, string msg)
        {
            rest = value % i;
            banknote = (int) value / i;
            value -= (banknote * i);
            WriteLine(banknote + msg + double.Parse(i.ToString()).ToString("n2"));
        }
        static void MethodCoins(int i, string msg)
        {
            rest = value % i;
            banknote = (int)value / i;
            value -= (banknote * i);
            string coinsValue = i<10?"0.0"+i:"0."+i;
            WriteLine(banknote + msg + coinsValue);
        }
    }
}