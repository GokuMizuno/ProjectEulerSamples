/*You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/
#include <iostream>
struct date
{
    int year;
    int month;
    int day;
    int dow; //day of week.  Sun = 0; Sat = 6
};

int main()
{
	int count = 0;
    int cycle = 0;  //cycles between 0-3, corresponds to leap year data
    date p19;
    p19.year = 1900;
    p19.month = 1;
    p19.day = 1;
    p19.dow = 1;
    /*Since 1900 is evenly divisble by 4, we count all leap years from there.
      2000 is div by 400, so it is a leap year.*/
    /*std::cout << "1901 % 4 is: " << 1901%4 << ", " << (1901>>2) << std::endl;
      outputs:  1901%4 is: 1, 475*/
    
    if(p19.year == 1900)
	{
        //add 365 days
		p19.dow = (365%6);
        p19.year++;
        cycle++;
    }
	p19.day = 7-p19.dow; //should these go above?
	p19.dow = 0;
	
	while(p19.year < 2001)
    {
        //do math  need to add loop for weeks, this only loops through years;
        /*Find Sundays.  Then add 7 to days, check against month, if day>month_length
          month++.  if(day==1,dow==0)counter++*/
        p19.day += 7;
        switch(p19.month)
        {
            case 1:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            /*TEST FOR LEAP YEAR*/
            case 2:
              if(cycle == 0) //leap year
              {
                  if(p19.day > 29)
                  {
                      p19.month++;
                      p19.day -= 29;
                      break;
                  }
				  else
					  break;
              }
              else //cycle !=0
              {
                  if(p19.day > 28)
                  {
                      p19.month++;
                      p19.day -= 28;
                      break;
                  }
				  else
					  break;
              }
            case 3:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            case 4:
              if(p19.day > 30)
              {
                  p19.month++;
                  p19.day -= 30;
                  break;
              }
            case 5:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            case 6:
              if(p19.day > 30)
              {
                  p19.month++;
                  p19.day -= 30;
                  break;
              }
			  else
				  break;
            case 7:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            case 8:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            case 9:
              if(p19.day > 30)
              {
                  p19.month++;
                  p19.day -= 30;
                  break;
              }
			  else
				  break;
            case 10:
              if(p19.day > 31)
              {
                  p19.month++;
                  p19.day -= 31;
                  break;
              }
			  else
				  break;
            case 11:
              if(p19.day > 30)
              {
                  p19.month++;
                  p19.day -= 30;
                  break;
              }
			  else break;
            case 12:
              if(p19.day > 31)
              {
                  p19.month = 1;
                  p19.day -= 31;
                  p19.year++;
                  if(cycle == 3)
                  {
                      cycle = 0;
                  }
                  else
                  {
                      cycle++;
                  }
                  break;
              }
			  else
				  break;
            default:
            {
                std::cout << "Something went wrong.  Dumping data: "
                << p19.day << ", " << p19.month << ", " << p19.year
                << ", " << p19.dow << ", " << count << ", "
                << cycle << std::endl;
                break;
            }
        }
        if(p19.day == 1)
        {  count++;  }
    }
    std::cout << "The total number of Sundays that fall on the first"
    << "of the month is: " << count << std::endl;
   return 0;
}