using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Rhello : abs
    {
        public Rhello(string name,int age) : base(name, age)
        {
            this.name = name;
            this.age = age;
        }
        public override void print()
        {
            Console.WriteLine("Name : " + name);
            Console.WriteLine("age : " + age);
        }
    }
}
