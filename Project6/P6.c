#include <iostream>
using namespace std;

int main()
{
	int a,b;
	a=0;
	b=0;

	for(int i=100;i>0;i--)
	{
		a+=(i*i);
		b +=i;
	}
	b *=b;
	printf("The difference between the square of the sums, and the sum of the squares for the first 100 natural numbers is %d\n", (b-a));

	return 0;
}