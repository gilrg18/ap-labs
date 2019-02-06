#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strlen(char *str){
    int count = 0;
    while(str[count]!= '\0'){
        count++;
    }
    return count;
}

char *stradd(char *origin, char *addition){
  char *newSub;
	newSub = (char *)malloc(strlen(origin)+strlen(addition)+1);
	if(!newSub){
		return "-1";
	}
	int len = 0;
	for(int i = 0 ; origin[i] != '\0'  ; i++){
		newSub[i] = origin[i];
		len = i;
	}
	int j = 0;
	for(int i = len  ; addition[i] != '\0' ; i++){
		newSub[i] = addition[j];
		j += 1; 
	}
	newSub[j] = '\0';
	return newSub;
}

int strfind(char *origin, char *substr){
	int found = 1; //True = 0 , False = 1
	int flag;
	int lenSubstr;

	for(int i = 0  ; substr[i] != '\0' ; i++){
		lenSubstr = i;
	}

	for(int i = 0; i < origin[i] != '\0' ; i++){
		if(origin[i] == substr[0]){
			flag = lenSubstr;
			for(int j = 0 ; j < lenSubstr  && origin[j+i] != '\0' ; j ++){
				if (substr[j] == origin[j+i]){
					flag -= 1;
				}
				if(flag == 0){
					return 0;
				}
			}	
		}
	}	
	return found;
}
