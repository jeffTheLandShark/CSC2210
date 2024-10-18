//============================================================================
// Name        : date.h
// Author      : Leigh Goetsch
//============================================================================

#ifndef DATE_H
#define DATE_H
#include <string>

/**
* @brief Represents a calendar date
*
* This class provides functionality for storing dates
*/
class Date {
public:
  Date(int month, int day, int year);

  Date();

  int month() const;

  int day() const;

  int year() const;

  std::string to_string() const;

  /**
   * @brief Determines if the first date occurs before the second date
   */
  static bool earlier(Date d1, Date d2);

  /**
   * @brief Determines if the date is a real date within the range 01/01/2000 - 12/31/3000
   */
  static bool valid_date(Date date);

private:
  int _month;
  int _day;
  int _year;
};
#endif //DATE_H
