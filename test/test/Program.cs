using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

delegate void Delegate();

namespace test
{    

    class Program
    {
       public static void Main(string[] args)
        {
            foreach (string s in args)
                Console.WriteLine(s);
        }
    }
}
