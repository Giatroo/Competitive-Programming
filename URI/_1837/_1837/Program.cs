using System;

namespace _1837
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] sin = Console.ReadLine().Split(' ');
            int a = Convert.ToInt32(sin[0]), b = Convert.ToInt32(sin[1]);
            int q = 0, r = 0;

            if (a >= 0)
            {
                if (b > 0)
                {
                    q = a / b;
                    r = a % b;
                }
                else
                {
                    q = a / b;
                    r = a % b;
                }
            }
            else
            {
                if (b < 0)
                {
                    int aux = a;
                    a = b;
                    b = aux;

                    q = a / b;
                    r = a % b;
                }
            }


            Console.WriteLine("{0} {1}", q, r);
        }
    }
}
