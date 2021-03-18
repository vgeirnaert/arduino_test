#include "DisplayService.h"
#include "SequentialTasklet.h"
#include "RepeatingTasklet.h"
#include "TimerTasklet.h"
#include "DisplayTasklet.h"

DisplayService::DisplayService() {
	defaultTasklet = new RepeatingTasklet(
    		(new SequentialTasklet())
    			->addTasklet(new DisplayTasklet("Oh yeah", 2000))
    			->addTasklet(new DisplayTasklet("It's working", 2000))
    			->addTasklet(new DisplayTasklet("ALFReD v3!", 2000))
    			->addTasklet(new TimerTasklet(3000)), -1);

	glassTasklet = new DisplayTasklet("", 2000);
}

void DisplayService::init() {
   	tasklet = defaultTasklet;
}

void DisplayService::onTick(Context context) {
	if(context.glassContext.hasGlass) {
		glassTasklet->setText("Glass: " + String(context.glassContext.distance));
		tasklet = glassTasklet;
	} else {
		tasklet = defaultTasklet;
	}

	if(tasklet->getStatus() == FINISHED) {
	return;
	}

	if(tasklet->getStatus() == PENDING) {
	tasklet->start();
	}

	tasklet->run();
}
