/*Gordon Stangler
Euler Problem 15
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20x20 grid?
*/
#include <iostream.h>

    const short gridsize = 20;
	/*C arrays start at 0, not one, so for a gridsize of 3, the elements are 0,1,2.*/
int main()
{
   unsigned long grid[gridsize][gridsize];
   short i,j;
   
   for(i=0;i<gridsize;i++)
	   for(j=0;j<gridsize;j++)
		   grid[i][j] = 0;

   i^=i;
   j^=j;
   
   //edges
   while(i<gridsize)
   {
       grid[i][j] = 1;
	  grid[j][i] = grid[i][j];  //symmetry
       i++;
   }

   i=1;
   while(i<gridsize)
   {
       j=1;
       while(j<gridsize)
       {
           grid[i][j] = grid[i-1][j] + grid[i][j-1];
           j++;
       }
       i++;
   }

   printf("%d", grid[gridsize-1][gridsize-1]);
   return 0;
}
