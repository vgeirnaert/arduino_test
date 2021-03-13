#include "DisplayService.h"
#include "SequentialTasklet.h"
#include "RepeatingTasklet.h"
#include "TimerTasklet.h"
#include "DisplayTasklet.h"

DisplayService::DisplayService() {
}

void DisplayService::init() {
   	tasklet = new RepeatingTasklet(
		(new SequentialTasklet())
			->addTasklet(new DisplayTasklet("Oh yeah", 2000))
			->addTasklet(new DisplayTasklet("It's working", 2000))
			->addTasklet(new DisplayTasklet("ALFReD v3!", 2000))
			->addTasklet(new TimerTasklet(3000)), -1);
}

void DisplayService::onTick() {
  if(tasklet->getStatus() == FINISHED) {
    return;
  }

  if(tasklet->getStatus() == PENDING) {
    tasklet->start();
  }

  tasklet->run();
}
