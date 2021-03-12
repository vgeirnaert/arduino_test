#include "Tasklet.h"

void Tasklet::reset() {
  setStatus(PENDING);
}

void Tasklet::setStatus(TaskletStatus status) {
  this->status = status;
}

TaskletStatus Tasklet::getStatus() {
  return this->status;
}
