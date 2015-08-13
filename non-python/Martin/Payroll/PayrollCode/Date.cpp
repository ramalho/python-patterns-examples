#include "Date.h"

long Date::secondsPerDay = 60L * 60L * 24L;

Date::Date()
{
  time_t now = time(NULL);
  itsTimeStruct = *(localtime(&now));
  itsTimeStruct.tm_sec = 0;
  itsTimeStruct.tm_min = 0;
  itsTimeStruct.tm_hour = 12;
  itsTime = mktime(&itsTimeStruct);
}

Date::Date(int month, int day, int year)
{
  bzero(reinterpret_cast<char*>(&itsTimeStruct), sizeof(itsTimeStruct));
  itsTimeStruct.tm_mon = month-1;
  itsTimeStruct.tm_mday = day;
  itsTimeStruct.tm_year = year-1900;
  itsTimeStruct.tm_sec = 0;
  itsTimeStruct.tm_min = 0;
  itsTimeStruct.tm_hour = 12;
  itsTime = mktime(&itsTimeStruct);
  itsTimeStruct = *(localtime(&itsTime));
}

Date::Date(const Date& theDate)
{	
  *this = theDate;	
}

Date::~Date() {}

Date& Date::operator= (const Date& theDate)
{
  itsTime = theDate.itsTime;
  itsTimeStruct = *(localtime(&itsTime));
  return *this;
}

int Date::GetMonth() const {return itsTimeStruct.tm_mon + 1;}
int Date::GetDay() const   {return itsTimeStruct.tm_mday;}
int Date::GetYear() const  {return itsTimeStruct.tm_year+1900;}

Date::DayOfWeek Date::GetDayOfWeek() const
{
  return (DayOfWeek)(itsTimeStruct.tm_wday);
}

string Date::GetDayOfWeekName() const
{
  string retval;
  switch(GetDayOfWeek())
    {
    case sunday:
      retval = "Sunday";
      break;
    case monday:
      retval = "Monday";
      break;
    case tuesday:
      retval = "Tuesday";
      break;
    case wednesday:
      retval = "Wednesday";
      break;
    case thursday:
      retval = "Thursday";
      break;
    case friday:
      retval = "Friday";
      break;
    case saturday:
      retval = "Saturday";
      break;
    }
  return retval;
}

ostream& operator<< (ostream& o, const Date& theDate)
{
  o << theDate.GetMonth() << '/'
    << theDate.GetDay() << '/'
    << theDate.GetYear();
  return o;
}

istream& operator>> (istream& i, Date& theDate)
{
  int month, day, year;
  char slash;
  i >> month >> slash >> day >> slash >> year;
  Date tmp(month, day, year);
  theDate = tmp;
  return i;
}

int Date::operator== (const Date& theDate) const
{
  return itsTime == theDate.itsTime;
}

int Date::operator!= (const Date& theDate) const
{
  return itsTime != theDate.itsTime;
}

int Date::operator< (const Date& theDate) const
{
  return itsTime < theDate.itsTime;
}

int Date::operator> (const Date& theDate) const
{
  return itsTime > theDate.itsTime;
}

int Date::operator<= (const Date& theDate) const
{
  return itsTime <= theDate.itsTime;
}

int Date::operator>= (const Date& theDate) const
{
  return itsTime >= theDate.itsTime;
}

Date operator+ (int days, const Date& theDate)
{
  Date retval = theDate;
  retval += days;
  return retval;
}

Date operator+ (const Date& theDate, int days)
{
  return days + theDate;
}

Date Date::operator- (int days) const
{
  Date retval = *this;
  retval -= days;
  return retval;
}

int Date::operator- (const Date& theDate) const
{
  return (itsTime - theDate.itsTime) / secondsPerDay;
}

Date& Date::operator+= (int days)
{
  itsTime += days * secondsPerDay;
  itsTimeStruct = *(localtime(&itsTime));
  return *this;
}

Date& Date::operator-= (int days)
{
  itsTime -= days * secondsPerDay;
  itsTimeStruct = *(localtime(&itsTime));
  return *this;
}

Date& Date::operator++ ()
{
  return ((*this) += 1);
}

Date Date::operator++ (int)  // postfix
{
  Date retval = *this;
  (*this) += 1;
  return retval;
}

Date& Date::operator-- ()
{
  return ((*this) -= 1);
}

Date Date::operator-- (int)  // postfix
{
  Date retval = *this;
  (*this) -= 1;
  return retval;
}
