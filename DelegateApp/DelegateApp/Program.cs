using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

delegate void SampleDelegate(); //델리게이트 정의

class DelegateClass
{
    public void DelegateMethod()    //델리게이트할 메소드
    {
        Console.WriteLine("In the DelegateClass.DelegateMethod...");
    }
}

namespace DelegateApp
{
    class Program
    {
        static void Main(string[] args)
        {
            DelegateClass obj = new DelegateClass();    //클래스 객체 생성
            SampleDelegate sd = new SampleDelegate(obj.DelegateMethod); //델리게이트 객체 생성
            sd();   //invoke obj.DelegateMethod() indirectly.
        }
    }
}
