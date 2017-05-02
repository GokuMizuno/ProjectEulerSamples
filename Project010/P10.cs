//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P10
Sum all the primes under two million
*/

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //I am going to use the Sieve of Atkins to pull out all the composite numbers
            int[] primes = Atkins(2000000);
            int sum = 0;
            for(int i=0;i<primes.Length;i++)
                sum += primes[i];
            
            Console.WriteLine("{0}", sum);
        }
        
        public static int[] Atkins(int max)
        {
            BitArray primeBits = new BitArray(max+1, false);
            int maxsqrt = (int)Math.Sqrt(max);
            List<int> listOfPrimes = new List<int>();
            
            for(int i=1; i<=max;i++)
            {
                for(int j=1;j<=max;j++)
                {
                    int n = 4*i*i*j*j;
                    if((n<=max)&&((n%12 == 1)||(n%12 == 5)))
                        primeBits.Set(n, !primeBits.Get(n));
                    n = 3*i*i*j*j;
                    if((n<=max)&&(n%12 == 7))
                        primeBits.Set(n, !primeBits.Get(n));
                    n = 3*i*i-(j*j);
                    if((n<=max)&&(n%12 == 11))
                        primeBits.Set(n, !primeBits.Get(n));
                }
            }
            
            for(int i=5;i<=max;i++)
            {
                if(primeBits.Get(i))
                {
                    for(int j=i*i;j<=max;j+=(i*i))
                        primeBits.Set((int)j,false);
                }
            }
            
            listOfPrimes.Add(2);
            listOfPrimes.Add(3);
            for(int i=5;i<=max;i+=2)
            {
                if(primeBits.Get(i))
                    listOfPrimes.Add(i);
            }
            
            return listOfPrimes.ToArray();
        }
    }
}
