//============================================================================
// Name        : appointments.cpp
// Author      : TODO: fill in name
//============================================================================

#include "appointments.h"
#include <string>
#include <iostream>
// add other includes as needed here, but appointments.h must be the FIRST include

// TODO: implement function before()


// TODO: implement the version of Appointment::Appointment that takes
//       a date and a description. This constructor needs to trim all
//       leading and trailing spaces from the description. You can use
//       .erase(0, 1) to remove the first character from a string if it is
//       a space (until some character is found that's not a space) and
//       then use .pop_back() to remove the last character until you reach
//       some character that is not a space. You can assume the description
//       has at least one letter in it.


void Schedule::add(Appointment new_appointment)
{
  int pos = 0;

  // TODO: set pos to the position new_appointment would appear in
  //       appointments[]. That is, write a while loop that terminates when
  //       pos >= num_appointments or when
  //       before(appointments[pos], new_appointment) is false
  while (
      ++pos;

  // do not change any of the rest of this method
  for(int i = num_appointments; i > pos; --i)
  appointments[i] = appointments[i - 1];
if ( pos < num_appointments )
appointments[pos] = new_appointment;
else
appointments[num_appointments] = new_appointment;
++num_appointments;
}

// TODO: implement write_to_cout so it writes all of the appointments,
//       one to a line

