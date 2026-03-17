using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class human
    {
        string name;
        int age;
        int height;
        bool married;
        bool live;
        public human():this("Unknow",32)
        {

        }
        public human(string name,int age)
        {
            this.name = name;
            this.age = age;
        }
// int[5] arr;
        public human(int age)
        {
            this.age = age;
            this.name = "Unknow";
        }
       public static int add(int num,int num2)
        {
            return num + num2;
        }
    }
}
