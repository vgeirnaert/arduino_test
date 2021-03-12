#include "TickableService.h"

void TickableService::setInterval(unsigned int tickIntervalMillis) {
  interval = tickIntervalMillis;
}

void TickableService::tick(unsigned long elapsedMillis) {
  // handle overflow after x time
  if(elapsedMillis < previousTickMillis) {
    previousTickMillis = 0;
  }

  // trigger onTick only at the appropriate time
  if(elapsedMillis - previousTickMillis > interval) {
    previousTickMillis = elapsedMillis;
    onTick();
  }
}
