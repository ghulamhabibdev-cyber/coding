using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    abstract class abs
    {
        protected string name;
        protected int age;
        public abstract void print();
        public abs(string name,int age)
        {
            this.name = name;
            this.age = age;
        }
    }
}
