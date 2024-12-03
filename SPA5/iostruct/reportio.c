// reportio.c: review inputs and outputs and report appropriately
// NOTE: this version will just look at high output, not retention

#include "event.h"
#include <stdio.h>
#include <string.h>

void flag_large_differentials(const Event events[], int event_count) {
  int total = 0;
  for (int i = 0; i < event_count; ++i) {

    if (events[i].is_output) {
      total -= events[i].mL;

    } else {
      total += events[i].mL;
      if (total >= 1000) {
        printf("after consuming %s at %s, intake exceeds output by %d ml\n",
               events[i].item, events[i].time, total);
      }
    }
  }
  printf("the final fluid differential is %d ml\n", total);
}
