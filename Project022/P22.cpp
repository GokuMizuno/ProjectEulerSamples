/*Gordon Stangler
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?
*/

/*Sln:
  Open file, and push strings from file into new strings, with pointer foo.
  Sort foo.
  for(each char in string)
  {  sum letters in string  }
  add string sum to total sum.  Total sum should be BigInt, or int64.
  delete[] strings.*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>	//for sort

__int64 getScore(std::string s)
{
	unsigned __int64 sum;
	sum ^= sum;
	for(unsigned int i=0;i<s.length();i++)
		sum += ((int) s.at(i) - 64);
	return sum;
}

__int64 getTotalScore(std::vector<std::string> names)
{
	unsigned __int64 sum;
	sum ^= sum;
	for(unsigned int i=0;i<names.size();i++)
		sum += (getScore(names[i])*(i+1));
	return sum;
}

bool userSortString(std::string x, std::string y)//std::vector<std::string> x, std::)
{
	if(x.compare(y) < 0)
		return true;
	else
		return false;
}

int main()
{
	unsigned __int64 sum;
	sum ^= sum;
	std::ifstream FILE;
	char currchar;
	std::string currname;
	currname = "";
	std::vector<std::string> names;
	names.reserve(5000);

	try
	{
		FILE.open("names.txt", std::fstream::in); //read only, ios::in is no longer valid
		while(!FILE.eof())
		{
			//get line after line, each line goes to new string
			//doing it with strings is much easier than using a char array
			currchar = FILE.get();
			if(isalpha(currchar))
				currname.push_back(currchar);
			else
				if(!currname.empty())
				{
					names.push_back(currname);
					currname.clear();
				}
		}
		FILE.close();
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "Unable to open file.  Aborting program.\n";
		FILE.close();
		return 0;
	}

	//We have to define our own sort, as std::sort(RanIt begin, RanIt end) is a C++11 function
	std::sort(names.begin(),names.end(), userSortString);//std::greater<std::string>());  //built in sorts FTW!
	std::cout << "The total score of all the names in names.txt is " << getTotalScore(names) << std::endl;

	return 0;
}
