// Logger

int initLogger(char* logType);
int infof(const char* tag, const char* message);
int warnf(const char* tag, const char* message);
int errorf(const char* tag, const char* message);
int panicf(const char* tag, const char* message);