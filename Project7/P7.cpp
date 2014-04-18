/*Gordon Stangler
Euler Problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?

Solution:  We are going to use a Sieve of Eratosthenes, filter out the composites, and then count the primes.
It should be around ln(10001)*10001 which is about 92,000.  So, we should test the first 120,000 numbers
to make sure we got it.  Brute force and inelegent?  Yes.  Quick?  Absolutely.
*/

#include <iostream>
#include <vector>
using std::vector;

void main()
{
	int i, TEST, count;
	TEST = 120000;
	count = 0;
	vector<int> map;
	vector<int>::iterator it;
	map.reserve(TEST);

	/*Map is the list of numbers from 0 to 120,000.  It is set to either 0 for prime, or 1 for composite
	The numbers 0 and 1, not being prime, are set to 1*/
	map.assign(TEST,0);
	map.at(0) = 1;
	map.at(1) = 1;

	/*We are going to grab the first number that begins with 0, and go down the line of map
	skipping to every i*prime, since that number would then be composite*/
	for(i=2;i<TEST;++i)
	{
		if(map.at(i) == 0)
			for(int a=i+i;a<map.size();a+=i)
				map.at(a) = 1;
//			for(*j=i;j != map.end();j+=i)  /*vector<int>::iterator j=map.at(i)*/
//			for(*j=map.at(i);j != map.end();*j+=i)  /*error, no operator "=" matches these operands if j=map.at(i)*/
//				map.at(*j) = 1;
		else
			continue;
	}

	for(it=map.begin();it != map.end();++it)
	{
		if(*it == 0)
			count++;
		if(count == 10001)
		{
			std::cout << "The 10,001 prime is: " <<(it - map.begin());
			break;
		}
	}
}


