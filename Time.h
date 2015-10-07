#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    // constructor
    Time(int h, int m, char c);
    Time(const Time &rhs);

    // accessor functions
    int getHours() const;
    int getMinutes() const;
    char getAMPM() const;

    // mutator functions
    void setHours(int h);
    void setMinutes(int m);
    void setAMPM(char c);
    
    // overloaded operator functions
    const Time operator=(const Time &rhs); 
    Time operator +(const Time&);
    Time operator -(const Time &);
    Time operator ++();
    Time operator ++(int);
    bool operator >(const Time &);
    bool operator <(const Time &);
    bool operator ==(const Time &);    

 private:
	const int HOUR = 60;
	const int DAY = 24;
	const int ZERO = 0;
	const int ONE = 1;
   
    int hours;
    int minutes;
    char ampm;    
    
    // helper function to deal with time borders
    void simplify();
};
#endif
