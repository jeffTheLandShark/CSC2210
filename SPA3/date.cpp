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
  : _month{month}, _day{day}, _year{year} {
}

Date::Date() : _month{0}, _day{0}, _year{0} {
}

int Date::month() const {
  return _month;
}

int Date::day() const {
  return _day;
}

int Date::year() const {
  return _year;
}

string Date::to_string() const {
  // ostringstreams provide an cout-like interface but store the results
  //   in a std:string instead of files; this convert data into a string
  ostringstream formatted;
  if (_month < 10)
    formatted << "0";
  formatted << _month << "/";
  if (_day < 10)
    formatted << "0";
  formatted << _day << "/" << _year;

  return formatted.str();
}

bool Date::earlier(Date d1, Date d2) {
  return d1.year() < d2.year() ? true : d1.month() < d2.month() ? true : d1.day() < d2.day();
}

// TODO: if useful to your design, add code to check for valid dates
