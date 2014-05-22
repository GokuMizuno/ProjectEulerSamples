/*Coin sums
Problem 31

In England the currency is made up of pound, L, and pence, p, and there are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, L1 (100p) and L2 (200p).
It is possible to make L2 in the following way:
    1xL1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
How many different ways can L2 be made using any number of coins?
*/

#include <iostream>
int main()
{
	int target = 200;
	int ways = 0;

	for(int a=target;a>=0;a-=200)
		for(int b=a;b>=0;b-=100)
			for(int c=b;c>=0;c-=50)
				for(int d=c;d>=0;d-=20)
					for(int e=d;e>=0;e-=10)
						for(int f=e;f>=0;f-=5)
							for(int g=f;g>=0;g-=2)
								ways++;

	std::cout << "There are " << ways << " of generating 200 pence." << std::endl;
	return 0;
}
