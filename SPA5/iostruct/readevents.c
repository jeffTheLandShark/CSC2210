// readevents.c - code to read and classify the events

#include "event.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void read_events(Event all_events[], int max_events, int *event_count) {
  char time[MAX_TIME_LENGTH + 1]; // add 1 for null terminator
  int milliliters;
  assert(MAX_EVENT_NAME < 80);
  // issue: protect against buffer overrun by making sure no name is too
  //        long. One *can* use MAX_EVENT_NAME in the scanf format string,
  //        but it makes the code more obscure. So here's a case where we
  //        simply use a hard-coded constant with a check to make sure
  //        that it's large enough for the following code to make sense.
  char item[80];

  *event_count = 0;
  int fields_read = scanf("%5s %79s %d", time, item, &milliliters);
  // read until we read a partial record (< 3 elements), eof, or max_events
  while (fields_read == 3 && !feof(stdin) && *event_count < max_events) {
    strncpy(all_events[*event_count].time, time, MAX_TIME_LENGTH);
    all_events[*event_count].mL = milliliters;
    strncpy(all_events[*event_count].item, item, MAX_EVENT_NAME);

    *event_count += 1;

    // note: is_output is set elsewhere
    // read for next time through loop
    fields_read = scanf("%5s %79s %d", time, item, &milliliters);
  }
}

void determine_if_event_is_output(Event *an_event) {
  if (strcmp(an_event->item, "urine") == 0 ||
      strcmp(an_event->item, "bloodloss") == 0 ||
      strcmp(an_event->item, "diarrhea") == 0) {
    an_event->is_output = true;
  } else {
    an_event->is_output = false;
  }
}

void classify_events(Event events[], int event_count) {
  for (int i = 0; i < event_count; ++i) {
    determine_if_event_is_output(&events[i]);
  }
}
