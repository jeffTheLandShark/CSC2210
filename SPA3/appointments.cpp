//============================================================================
// Name        : appointments.cpp
// Author      : Leigh Goetsch
//============================================================================

#include "appointments.h"
#include <iostream>

using namespace std;

bool before(Appointment a, Appointment b) {
  return Date::earlier(a.date(), b.date());
}

Appointment::Appointment(Date date, std::string description) {
  bool leading = description[0] == ' ';
  bool trailing = description[description.length() - 1] == ' ';
  while (leading || trailing) {
    if (leading) {
      description.erase(0, 1);
      leading = description[0] == ' ';
    }
    if (trailing) {
      description.pop_back();
      trailing = description[description.length() - 1] == ' ';
    }
  }
  _date = date;
  _description = description;
}

void Schedule::add(Appointment new_appointment) {
  if (Date::valid_date(new_appointment.date())) {
    int pos = 0;
    while (pos < num_appointments && before(appointments[pos], new_appointment)) {
      ++pos;
    }

    // do not change any of the rest of this method
    for (int i = num_appointments; i > pos; --i)
      appointments[i] = appointments[i - 1];
    if (pos < num_appointments)
      appointments[pos] = new_appointment;
    else
      appointments[num_appointments] = new_appointment;
    ++num_appointments;
  }
}

void Schedule::write_to_cout() const {
  for (int i = 0; i < num_appointments; ++i) {
    cout << appointments[i].date().to_string() << ": " << appointments[i].description() << endl;
  }
}
