using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Book
    {
        public string title;
        public string author;
        public void print()
        {
            Console.Write("Title " + title);
            Console.WriteLine("Author " + author);
          
        }
    }
}
