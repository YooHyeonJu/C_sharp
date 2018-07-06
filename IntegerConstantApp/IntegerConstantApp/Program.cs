using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntegerConstantApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 255, h = 0xff;
            long l = 0xffL;
            Console.WriteLine("i = {0}, h = {1}", i, h);
            if (h == l)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}
