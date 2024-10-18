//============================================================================
// Name        : date.cpp
// Author      : Leigh Goetsch
//============================================================================

//
// Make no changes to this file other than the TODOs below
//

#include "date.h"

#include <iomanip>
#include <iostream>
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
  formatted << std::setw(2) << std::setfill('0') << _month << "/";
  formatted << std::setw(2) << std::setfill('0') << _day << "/";
  formatted << std::setw(4) << std::setfill('0') << _year;
  return formatted.str();
}

bool Date::earlier(Date d1, Date d2) {
  return d1.year() < d2.year() ||
         (d1.year() == d2.year() &&
          (d1.month() < d2.month() ||
           (d1.month() == d2.month() && d1.day() < d2.day())));
}

bool Date::valid_date(Date date) {
  if (date.month() < 1 || date.month() > 12) {
    cout << "ERROR: invalid month in " << date.to_string() << endl;
    return false;
  }
  int max_day;
  switch (date.month()) {
    case 4:
    case 6:
    case 9:
    case 11:
      max_day = 30;
      break;
    case 2:
      max_day = 29;
      break;
    default:
      max_day = 31;
  }
  if (date.day() > max_day || date.day() < 1) {
    cout << "ERROR: invalid day in " << date.to_string() << endl;
    return false;
  }
  if (date.year() < 2000 || date.year() > 3000) {
    cout << "ERROR: invalid year in " << date.to_string() << endl;
    return false;
  }
  return true;
}
