/*Gordon Stangler
  Euler problem 5
  Find the lcm of 1-20 inclusive

  Shortcuts:
    lcm(a,b) = |a*b|/gcd(a,b) = (|a|/gcd(a,b))*|b|
*/

#include <iostream>

int gcd(int a, int b)
{  return 0 == b ? a : gcd(b, a%b);  }

int main()
{
	int i, flag;
	flag = 0;

	for(i=20;;i+=20)
	{
		for(int j=20;j>0;j--)
		{
			if(0 != i%j)
				break;
			if(j == 1)
				flag = 1;
		}
		if(flag == 1)
			break;
	}
//		sum += (double)i/gcd(i,i--) * i--;
	std::cout << "LCM of 1-20 inclusive is " << i << std::endl;
	return 0;
}