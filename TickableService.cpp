#include "TickableService.h"

void TickableService::setInterval(unsigned int tickIntervalMillis) {
  interval = tickIntervalMillis;
}

void TickableService::tick(Context context) {
  // handle overflow after x time
  if(context.currentTime < previousTickMillis) {
    previousTickMillis = 0;
  }

  // trigger onTick only at the appropriate time
  if(context.currentTime - previousTickMillis > interval) {
    previousTickMillis = context.currentTime;
    onTick(context);
  }
}
