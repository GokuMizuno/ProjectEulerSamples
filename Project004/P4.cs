//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5
/*Gordon Stangler
Project Euler P4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/


using System;
//using System.Boolean;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int product,palendrome;
            palendrome = 0;
            
            for(int a=100;a<1000;a++)
            {
                for(int b=100;b<1000;b++)
                {
                    product = a*b;
                    if((product>palendrome)&&(isPalendrome(product)))
                        palendrome = product;
                }
            }
            Console.WriteLine("The largest palendrome found is: {0}", palendrome);
        }
        
        public static bool isPalendrome(int number)
        {
            int orig, reversed;
            orig = number;
            reversed=0;
            
            while(number > 1)
            {
                reversed = (10*reversed)+(number%10);
                number = number/10;
            }
            
            if(orig == reversed)
                return true;
            else
                return false;   
        }
    }
}
