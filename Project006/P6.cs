//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P6
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

We know that the sum of consecutive numbers is S = /frac{N*(N+1)}{2}
the square of the sum of consecutive numbers is S^2_{n} = /frac{n*(n+1)*(2*n+1)}{6}
*/

using System;
using System.Collections.Generic;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            long N, sum, sqsum;
            
            N = 100;
            sum = (N*(N+1))/2;
            sqsum = (N*(N+1)*(2*N+1))/6;
            
            Console.WriteLine("{0}", (sum*sum)-sqsum);
        }
    }
}
