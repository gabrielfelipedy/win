#ifndef _H_CONST
#define _H_CONST

enum modes {
	OFF = 0,
	ON
};

typedef struct {
    int addMode;
	int sMode;
	bool isProcessing;
	bool finishedEdit;
} config_t;

extern config_t application;

bool isEmpty();

#endif