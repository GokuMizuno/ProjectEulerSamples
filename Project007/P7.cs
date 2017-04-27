//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P7
Find the 10,001st prime number.
*/

using System;
using System.Collections.Generic;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
           int upperLimit = 10001;                        
           int counter = 1;

           bool isPrime;
           int j;
           List<int> primes = new List<int>();

           primes.Add(2);          
            
           while(primes.Count < upperLimit)
           {
                counter += 2; 
                j = 0;
                isPrime = true;
                while (primes[j]*primes[j] <= counter) 
                {
                    if (counter % primes[j] == 0)
                    {
                        isPrime = false;
                        break;
                    }
                    j++;
                }
                if (isPrime)
                {
                    primes.Add(counter);
                }
           }
            //use upperLimit-1, since we start at 0, not 1
            Console.WriteLine("{0} is the 10,001st prime", primes[upperLimit-1]);
        }
    }
}
