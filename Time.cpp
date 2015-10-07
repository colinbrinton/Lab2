#include "Time.h"

/***************
 * CONSTRUCTORS *
 ***************/

Time::Time(int h, int m)
  :hours(h), minutes(m)
{
  simplify();
}

Time::Time(const Time &rhs)
{
  hours = new int (*rhs.hours);
  minutes = new int (*rhs.minutes);
}                                                         

/********************
 * PUBLIC FUNCTIONS *
 ********************/
                                                                                   
// accessor functions                                                          

int Time::getHours() const
{
  return hours;
}
                                                          
int Time::getMinutes() const                                                        
{         
  return minutes;                                                                      
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
	  *hours = *rhs.hours;
	  *minutes = *rhs.minutes;
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
  ++inches;
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
  return (hour == rhs.hours && minutes ==  rhs.minutes)
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
