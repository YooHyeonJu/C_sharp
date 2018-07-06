using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//1. 델리게이트 정의
//C#에서 제공하는 EventHandler 델리게이트를 사용함.

namespace EventApp
{
    class EventApp
    {
        public EventHandler MyEvent;    //2. 이벤트 선언
        void MyEventHandler(object sender, EventArgs e)     //3. 이벤트 처리기 작성
        {
            Console.WriteLine("Hello world");
        }
        public EventApp()   //생성자
        {
            this.MyEvent += new EventHandler(MyEventHandler);   //4. 이벤트 처리기 등록
        }
        public void InvokeEvent()
        {
            if (MyEvent != null)
                MyEvent(this, null);    //5. 이벤트 발생
        }
        static void Main(string[] args)
        {
            new EventApp().InvokeEvent();
        }
    }
}
