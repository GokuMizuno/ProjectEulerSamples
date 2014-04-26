#include <iostream>

    const short gridsize = 3;
//not working, and I have no idea why.
int main()
{
   unsigned long grid[gridsize][gridsize];
   unsigned long length;
   short i,j;
   i = j = 0;
   
   for(i=0;j<gridsize;i++)
   {
    for(j=0;j<gridsize;j++)
    {
        grid[i][j] = 0;
        std::cout << grid[i][j];
    }
    std::cout << std::endl;
   }
   i^=i;
   j^=j;
   
   while(i<=gridsize)
   {
       grid[i][j] = 1;
       std::cout << grid[i][j];
       i++;
   }
   i=1;
   while(i<=gridsize)
   {
       j=1;
       while(j<i)
       {
           grid[i][j] = grid[i-1][j]+grid[i][j-1];
           j++;
       }
       grid[i][j] = 2*grid[i-1][j];
       i++;
   }
   
   std::cout << grid[gridsize-1][gridsize-1] << std::endl;
   return 0;
}