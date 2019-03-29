#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

void print_status(long tgid);
void clear();

void print_status(long tgid) {
  char path[40], line[100], *p;
  char *pPid;
  FILE* statusf;

  snprintf(path, 40, "/proc/%ld/status", tgid);

  statusf = fopen(path, "r");
  if(!statusf)
    return;

  while(fgets(line, 100, statusf)) {
    
    if(strncmp(line, "State:", 6) == 0)
    {
      p = line + 7;
      while(isspace(*p)) ++p;
    }
    else
    {
      continue;
    }
    

    printf("%6ld %s", tgid, p);
  }
  fclose(statusf);
}

int main(){
  printf("PID   |   STATE");
  while(1){


    DIR* proc = opendir("/proc");
    struct dirent* ent;
    long tgid;

    if(proc == NULL) {
        perror("opendir(/proc)");
    return 1;
    }

    while((ent = readdir(proc))) {
        if(!isdigit(*ent->d_name))
            continue;

        tgid = strtol(ent->d_name, NULL, 10);

        print_status(tgid);
    }
    closedir(proc);
    sleep(2);
  }
    
    return 0;
}

void clear() {
    printf("\e[1;1H\e[2J"); 
}