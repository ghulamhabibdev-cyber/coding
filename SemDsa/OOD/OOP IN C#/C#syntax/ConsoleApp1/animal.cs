using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class animal
    {
       private string name;
        public int age;
        protected int wiehgt;

        public animal(string name)
        {
            this.name = name;
            age = 0;
            wiehgt = 0;
        }
        public void print()
        {
            Console.WriteLine("Name  : " + name);
        }
            
    }
}
