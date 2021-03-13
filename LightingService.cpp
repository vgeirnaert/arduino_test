#include "Arduino.h"
#include "LightingService.h"
#include "SequentialTasklet.h"
#include "RepeatingTasklet.h"
#include "PinTasklet.h"
#include "TimerTasklet.h"
#include "BlinkTasklet.h"
#include "ParallelTasklet.h"
#include "RGBFadeTasklet.h"
#include "DisplayTasklet.h"

LightingService::LightingService() {
}

void LightingService::init() {
  /*lightingTasklet = (new ParallelTasklet())
    ->addTasklet(
      new RepeatingTasklet(
        (new SequentialTasklet())
          ->addTasklet(new RepeatingTasklet(new BlinkTasklet(400, 200), 3))
          ->addTasklet(new TimerTasklet(3000))
      , -1)
    )
    ->addTasklet(
      new RepeatingTasklet(
        (new SequentialTasklet())
          ->addTasklet(new RepeatingTasklet(new BlinkTasklet(2000, 500), 2))
          ->addTasklet(new TimerTasklet(7000))
      , -1)
    );*/
   lightingTasklet = new RGBFadeTasklet(5000, 11000);
}

void LightingService::onTick() {
  if(lightingTasklet->getStatus() == FINISHED) {
    return;
  }
  
  if(lightingTasklet->getStatus() == PENDING) {
    lightingTasklet->start();
  }
  
  lightingTasklet->run();
}
