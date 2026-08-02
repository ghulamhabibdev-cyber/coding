using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        public static void HarmonicMean(params double[] arr)
        {
            double len = arr.Length;
            double sum = 0;
            for(int i=0;i<len;i++)
            {
                sum += 1.0 / arr[i];
            }
            double mean = sum / len;
            double HM = 1.0 / mean;
            Console.WriteLine("Hamronic mean  : " + HM);
        }
        public static void ArithmaticMean(params double [] arr)
        {
            double len = arr.Length;
            double sum = 0;
            for(int i=0;i<len;i++)
            {
                sum += arr[i];
            }
            double ArithMean = sum / len;
            Console.WriteLine("Arithmatic MEan iS : " + ArithMean);
        }
       public  static void GeomatricMean(params double[] arr)
        {
            double len = arr.Length;
            double sum = 1;
            for(int i = 0; i < len; i++)
            {
                sum *= arr[i];
            }
            //GM=(x1*,x2*x3)pow1/3;
           double geomatricMean= Math.Pow(sum, 1 / len);
            Console.WriteLine("Geomatric Mean : " + geomatricMean);
        }
        static void Main(string[] args)
        {
            HarmonicMean(2, 4.0, 6.0,6,6,6,6,6,6,6,6,6);
            ArithmaticMean(2.0, 4.0, 6.0,6,6,6,6,6,6,6);
            GeomatricMean(2, 2);
        }
    }
}
