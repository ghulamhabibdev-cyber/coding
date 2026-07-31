using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //int myInt = 5;
            //goto mylabel;
            //myInt += 10;
            //mylabel:
            //Console.WriteLine("my int : is : " + myInt);
            //int sum = 0;
            //for(int i = 0; i<=100; i++)
            //{
            //    sum += i;
            //    if(i==100)
            //    {
            //        goto newLable;
            //    }
            //}
            //sum *= 100;
            //newLable:
            //sum *= 2;
            //Console.WriteLine("MY num after " + sum);
            int intNum;
            char charNum = '3';
            intNum = (int)charNum;
            double doubleNum=intNum*100.5;
            Console.WriteLine("My char Is : " + charNum);
            Console.WriteLine("my int is : " + intNum);
            Console.WriteLine("my double is : " + doubleNum);
            float num = 12.04f;
            Console.WriteLine("my flaot is " + num);
            string numStringNum = "156";
            
            
        }
    }
}
