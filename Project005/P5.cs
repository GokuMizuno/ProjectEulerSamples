//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible (divisible with no remainder) by all of the numbers from 1 to 20?
*/

using System;
using System.Collections.Generic;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int maxNum = 20;
            int smallestNum = 1;
            int[] prime = CreatePrimes(maxNum);
            
            for(int i=0;i<prime.Length;i++)
            {
                int a = (int)Math.Floor(Math.Log(maxNum)/Math.Log(prime[i]));
                smallestNum *= ((int)Math.Pow(prime[i],a));
            }
            Console.WriteLine("{0} is the smallest possible number that is evenly divisible by 2..20 inclusive.", smallestNum);
        }
        
        static private int[] CreatePrimes(int upperLimit)
        {
            List<int> primes = new List<int>();
            bool isPrime;
            int i,j;
            
            primes.Add(2);
            for(i=3;i<=upperLimit;i++)  //for(;;i+2) throws an error
            {
                isPrime = true;
                j = 0;
                while(primes[j]*primes[j] <= i)
                {
                    if(i%primes[j] == 0)
                    {
                        isPrime = false;
                        break;
                    }
                    j++;
                }
                if(isPrime)
                    primes.Add(i);
            }
            
            return primes.ToArray<int>();
        }
    }
}
