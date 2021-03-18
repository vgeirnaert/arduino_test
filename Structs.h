#ifndef NonBlockingStructs_h
#define NonBlockingStructs_h

struct GlassContext {
	float distance;
	bool hasGlass;
};

struct Context {
	unsigned int currentTime;
	GlassContext glassContext;
};

#endif