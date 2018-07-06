using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Threading; //반드시 포함!!


namespace ThreadApp
{
    class ThreadApp
    {
        static void ThreadBody()    //스레드 몸체
        {
            Console.WriteLine("In the thread body ...");
        }

        static void Main(string[] args)
        {
            ThreadStart ts = new ThreadStart(ThreadBody);   //델리게이트 객체 생성

            //델리게이트 객체를 매개변수로 스레드 객체 생성
            Thread t = new Thread(ts);                   
            
            Console.WriteLine("*** Start of Main");

            //메소드를 호출하여 스레드의 실행을 시작함.
            t.Start();

            Console.WriteLine("*** End of Main");
        }
    }
}
