#ifndef TickableService_h
#define TickableService_h

class TickableService {
  public:
    void setInterval(unsigned int tickIntervalMillis);
    void tick(unsigned long elapsedMillis);
    virtual void onTick();
  private:
    unsigned int interval;
    unsigned long previousTickMillis = 0;
};

#endif
