using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace String_Logics
{
    class Program
    {
        static void MaxLenStringPrinter()
        {
            int len;
            int[] lenArray=new int[5];
            string[] myStrings = new string[5];
            for(int i = 0; i < myStrings.Length; i++)
            {
                Console.WriteLine("Enter Your Name : ");
                myStrings[i] = Console.ReadLine();
            }
            for (int i = 0; i < myStrings.Length; i++)
            {
                lenArray[i] = myStrings[i].Length;  
            }
            len = lenArray[0];
            int minlen = lenArray[0];
            for(int i = 0; i < lenArray.Length; i++)
            {
                if (lenArray[i] > len)
                {
                    len = lenArray[i];
                }
                if (lenArray[i] < minlen)
                {
                    minlen = lenArray[i];
                }
            }
            for(int i = 0; i < myStrings.Length; i++)
            {
                if (len == myStrings[i].Length)
                {
                    Console.WriteLine("MAX CHAR NAME IS : " + myStrings[i]);
                    
                }
                if(minlen==myStrings[i].Length)
                {
                    Console.WriteLine("Least Char Name : " + myStrings[i]);
                }
            }


        }
        static void Main(string[] args)
        {
            MaxLenStringPrinter();
        }
    }
}
