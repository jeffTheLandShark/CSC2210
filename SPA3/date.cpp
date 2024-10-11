//============================================================================
// Name        : date.cpp
// Author      : TODO: enter name
//============================================================================

//
// Make no changes to this file other than the TODOs below
//

#include "date.h"
#include <sstream>
using namespace std;

Date::Date(int month, int day, int year)
    : _month{month}, _day{day}, _year{year}
{ }

Date::Date() : _month{0}, _day{0}, _year{0} { }

int Date::month() const {
  return _month;
}

int Date::day() const {
  return _day;
}

int Date::year() const {
  return _year;
}

string Date::to_string() const
{
  // ostringstreams provide an cout-like interface but store the results
  //   in a std:string instead of files; this convert data into a string
  ostringstream formatted;
  if ( _month < 10 )
    formatted << "0";
  formatted << _month << "/";
  if ( _day < 10 )
    formatted << "0";
  formatted << _day << "/" << _year;

  return formatted.str();
}

bool earlier(Date d1, Date d2)
{
  // TODO: implement this; d1 is earlier than d2 if d1's year is earlier.
  //       If the years are the same, check months, and if the months
  //       are the same check the days.


}

// TODO: if useful to your design, add code to check for valid dates
