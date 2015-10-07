#include <cstdlib> //Needed for abs()
#include <iomanip> //Needed for setw() and setfill()
#include <iostream> //Needed for cout
#include "Time.h"

using namespace std;

/***************
 * CONSTRUCTORS *
 ***************/

Time::Time()
{
  hours = ZERO;
  minutes = ZERO;
}

Time::Time(int h, int m)
  :hours(h), minutes(m)
{
  simplify();
}

Time::Time(const Time &rhs)
{
  hours = rhs.hours;
  minutes = rhs.minutes;
}                                                         

/********************
 * PUBLIC FUNCTIONS *
 ********************/
                                                                                   
// accessor functions                                                          

void Time::displayTime()
{
  cout << this->getHours() << ":"
	   << setfill('0') << setw(2) << this->getMinutes();
}


// mutator functions                                                           
    
void Time::setHours(int h)                                                               
{           
  hours = h;                                                                   
}
    
void Time::setMinutes(int m)                                                             
{           
  minutes = m;                                                                    
}
                                                                                   
// overloaded Time::operator functions                                            
    
const Time Time::operator=(const Time &rhs)                                         
{
  if(this != &rhs )
	{
	  hours = rhs.hours;
	  minutes = rhs.minutes;
	}
  return *this;
}
    
Time Time::operator +(const Time&rhs)                                                  
{
  Time temp;
  temp.minutes = minutes + rhs.minutes;
  temp.hours = hours + rhs.hours;
  temp.simplify();
  return temp;
  
}
    
Time Time::operator -(const Time &rhs)                                                 
{
  Time temp;
  temp.minutes = minutes - rhs.minutes;
  temp.hours = hours - rhs.hours;
  temp.simplify();
  return temp;

}
    
Time Time::operator ++()                                                            
{
  ++minutes;
  simplify();
  return *this;

}
    
Time Time::operator ++(int)                                                         
{
  Time temp(hours, minutes);

  minutes++;
  simplify();
  return temp;
}
    
bool Time::operator >(const Time &rhs)                                                 
{                   
  return (hours > rhs.hours ||
		  (hours == rhs.hours && minutes > rhs.minutes))
				  ? true : false;
}
    
bool Time::operator <(const Time &rhs )                                             
{
  return (hours < rhs.hours ||
		  (hours == rhs.hours && minutes < rhs.minutes))
				  ? true : false;
}
    
bool Time::operator ==(const Time &rhs)  
{
  return (hours == rhs.hours && minutes ==  rhs.minutes)
	? true : false;
}

/********************                                                              
 * PRIVATE FUNCTIONS *                                                              
 ********************/ 

void Time::simplify()
{	  
  if(minutes >= HOUR)
	{
	  hours += (minutes / HOUR);
	  minutes = minutes % HOUR;
	}
  else if (minutes < ZERO)
	{
	  hours -= ((abs(minutes) / HOUR) + ONE);
	  minutes = HOUR - (abs(minutes) % HOUR);
	}
  
  if (hours >= DAY)
	hours = hours % DAY;
  
  else if (hours < ZERO)
	{
	  hours = DAY - (abs(hours) % DAY);
	}
}

int Time::getHours() const
{
  return hours;
}

int Time::getMinutes() const					\

{
  return minutes;								\

}
