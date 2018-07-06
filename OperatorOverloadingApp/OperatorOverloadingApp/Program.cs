using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Even
{
    int evenNumber;
    public Even(int n)  //생성자
    {
        evenNumber = (n % 2 == 0) ? n : n + 1;
    }
    public static Even operator++(Even e)   //++연산자 재정의
    {
        e.evenNumber += 2;  //다음 짝수
        return e;
    }
    public static Even operator--(Even e)   //--연산자 재정의
    {
        e.evenNumber -= 2;  //이전 짝수
        return e;
    }
    public void PrintEven() //출력 메소드
    {
        Console.WriteLine("Even Number = " + evenNumber);
    }
}

namespace OperatorOverloadingApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Even e = new Even(4);   e.PrintEven();
            e++;                    e.PrintEven();
            e--;                    e.PrintEven();
        }
    }
}
