#ifndef Tasklet_h
#define Tasklet_h

enum TaskletStatus {
  PENDING,
  ACTIVE,
  FINISHED
};

class Tasklet {
  public:
    TaskletStatus getStatus();
    virtual void start();
    virtual void run();
    virtual void reset();
    void setStatus(TaskletStatus status);
  protected:
    TaskletStatus status = PENDING;
};

#endif
