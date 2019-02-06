

int strlen(char *str);
char *stradd(char *origin, char *addition);
int strfind(char *origin, char *substr);

int main(int argc, char **argv){

  printf("Initial Lenght      : %d", strlen(argv[1]));
  printf("New String          : %s", stradd(argv[1],argv[2]));

  if(strfind(stradd(argv[1],argv[2]), argv[3]) == 1){
    printf("SubString was found : yes" );
  }
  else{
    printf("SubString was found : no" );
  }
}