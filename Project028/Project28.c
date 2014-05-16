/*Gordon Stangler
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Sln:  Each spiral has four corners, and the corners on each layer is offset from the previous layer by 2.
Layer 1:  1
Layer 2:  3,5,7,9
Layer 3:  13,17,21,25
Layer 4:  31,37,... and so on
This is the formula 4*(2n+1)^2 - 12n
*/
#include <stdio.h>

int main()
{
	unsigned __int64 sum = 1;
	int n;
	/*Step size is n
	  A 1001x1001 spiral does not hava 1001 layers.  FIX*/
	for(n=1;n<=500;n++)
		//(2n+1)^2 = 4n^2 + 4n + 1
		sum += 4*(4*(n*n) + 4*n +1) - 12*n;

	printf("The sum of the diagonals in a 1001x1001 spiral is %d", sum);
	return 0;
}
