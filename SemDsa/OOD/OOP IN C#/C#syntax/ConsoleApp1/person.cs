using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class person
    {
        string name;
        int age;
       public person():this("Unknow",21)
        {
            Console.WriteLine("I am called");
        }
       public person(string name,int age)
        {
            this.name = name;
            this.age = age;
        }
        public void printInformtion()
        {
            Console.WriteLine("Name : " + name);
            Console.WriteLine("age : " + age);
        }
    }
}
