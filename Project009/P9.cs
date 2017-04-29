//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler P9
Find the product of a,b,c, such that a*b*c < 1000, and a^2 + b^2 = c^2
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int a,b,c,m,n;
            
            for(m=1;m<1000;m++)
            {
                for(n=0;n<m;n++)
                {
                    a = (m*m - n*n);
                    b = 2*m*n;
                    c = (m*m + n*n);

                    if((a+b+c) == 1000)
                    {
                        Console.WriteLine("The product of a = {0}, b = {1}, and c = {2} is {3}.\n", a,b,c,(a*b*c));
                        break;
                    }
                }
                n=0;
            }
        }
    }
}