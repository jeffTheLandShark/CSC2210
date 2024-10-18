//============================================================================
// Name        : date.h
// Author      : Leigh Goetsch
//============================================================================

// TODO: add definitions and declarations so that date.cpp compiles
//       This includes code (#ifndef) to ensure class definitions appear just
//       once and including any headers for types that Date depends on.
//       Make sure you include appropriate documentation - see your class
//       style guide.

// TODO: Document the Date class by describing *what* it does, not how it does
//       it; that is, what are its responsibilities?


#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
public:
  Date(int month, int day, int year);

  Date();
  int month() const;
  int day() const;
  int year() const;
  std::string to_string() const;

  static bool earlier(Date d1, Date d2);

private:
  int _month;
  int _day;
  int _year;
};
#endif //DATE_H
