#include <iostream>

    const short gridsize = 3;
	/*C arrays start at 0, not one, so for a gridsize of 3, the elements are 0,1,2.*/
//not working, and I have no idea why.
int main()
{
   unsigned long grid[gridsize][gridsize];
//   unsigned long length;
   short i,j;
   i = j = 0; //needed?
   
   for(i=0;i<gridsize;i++)
   {
    for(j=0;j<gridsize;j++)
    {
        grid[i][j] = 0;
//        std::cout << grid[i][j];
    }
//    std::cout << std::endl;
   }
   i^=i;
   j^=j;
   std::cout << "i = " << i << " j = " << j << std::endl;
   
   //edges
   while(i<gridsize)
   {
       grid[i][j] = 1;
	   grid[j][i] = grid[i][j];  //symmetry
       std::cout << grid[i][j];
       i++;
   }
   std::cout << std::endl;
   i=1;
   while(i<gridsize)
   {
       j=1;
       while(j<=i)
       {
           grid[i][j] = grid[i-1][j] + grid[i][j-1];  //double check this
		   //the above line is failing in the grid[1][2] case.  Find out why.
           j++;
       }
//       grid[i][j] = 2*grid[i-1][j];
       i++;
   }
   
   /*Debugging*/
   for(i=0;i<gridsize;i++)
   {
    for(j=0;j<gridsize;j++)
    {
        std::cout << grid[i][j];
    }
    std::cout << std::endl;
   }

   //std::cout << grid[gridsize-1][gridsize-1] << std::endl;
   return 0;
}