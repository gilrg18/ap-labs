int infof(const char *format, ...);
int warnf(const char *format, ...);
int errorf(const char *format, ...);
int panicf(const char *format, ...);
void textcolor(int attr, int fg);

int main () {
    infof("%s\n", "INFO");
    warnf("%s\n", "WARN");
    errorf("%s\n" ,"ERROR");  
    panicf("%s\n", "PANIC");     
   return 0;
}