//============================================================================
// Name        : appointments.cpp
// Author      : TODO: fill in name
//============================================================================

#include "appointments.h"
#include <iostream>

using namespace std;

bool before(Appointment a, Appointment b) {
  return a.date().year() < b.date().year() ||
         (a.date().year() == b.date().year() &&
          (a.date().month() < b.date().month() ||
           (a.date().month() == b.date().month() && a.date().day() < b.date().day())));
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
}

void Schedule::add(Appointment new_appointment) {
  int pos = 0;

  while (pos >= num_appointments || !before(appointments[pos], new_appointment)) {
    ++pos;

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
    cout << appointments[i].description() << endl;
  }
}
