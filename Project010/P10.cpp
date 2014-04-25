#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> v;
    vector<int>::iterator it;
    long sum = 0;
    
    v.reserve(2000000);
    for(int i=0;i<2000001;i++)
    {  v.push_back(i);  }
    v.at(0) = 0;
    v.at(1) = 0;
    
    for(int i=2;i<2000001;i++)
    {
        for(int a=i+i;a<2000001;a+=i)
        {
            v.at(a) = 0;
        }
    }
    
    for(it=v.begin();it!=v.end();it++)
    {
        sum += *it;
    }
   
   std::cout << "The total of the first two million primes is " << sum;
   return 0;
}