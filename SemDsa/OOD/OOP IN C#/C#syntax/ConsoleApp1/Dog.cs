using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Dog:animal
    {
        public Dog(int wight,string name):base(name)

        {
            this.wiehgt = wight;
        }
        public void print()
        {
            base.print();
            Console.WriteLine(wiehgt);
        }
    }
}
