//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P3
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143
*/

using System;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            const long numToCheck = 600851475143;
            long factoredNum = numToCheck;
            long counter = 2;
            long largestFactor = 1;
            
            while((counter*counter) <= numToCheck)
            {
                if(0 == (factoredNum % counter))
                {
                    factoredNum /= counter;
                    largestFactor = counter;
                }
                else
                    counter++;
            }
            if(factoredNum > largestFactor)
                largestFactor = factoredNum;
            Console.WriteLine("{0} is the largest factor", largestFactor);
        }
    }
}
