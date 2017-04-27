/*Gordon Stangler
Project Euler P4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
int isPalendrome(unsigned int);

int main()
{
  unsigned int a,b,prod, pal;  //a and b are our three digit numbers, prod is the number itself, pal is the highest palendrome.

  pal = 0;
  a=999;
  while(a>99)
  {
    b=999;
    while(b>99)
    {
      prod=a*b;
        //prod>pal means new palendrome > old palendrome
      if((prod>pal)&&(isPalendrome(prod)))
        pal = prod;
      b--;
    }
    a--;
  }

  printf("The number %d was found to be the largest palendrome.\n", pal);
  return 0;
}

int isPalendrome(unsigned int num)
{
  unsigned int rev, org; //the reversed number, original number
  rev = 0;
  org = num;

  /*Would bitshifting make the loop faster?*/
  while(num > 1)
  {
    rev = (10*rev) + (num%10);
    num /= 10;
  }

  if(org == rev)  return 1;
  else  return 0;
}
