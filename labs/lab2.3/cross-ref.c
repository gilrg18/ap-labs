#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct s_words {
    char *str;            
    int count;            
    struct s_words *next; 
} words;

words *create_words(char *word){
    words *tmpWord = malloc(sizeof(words));
    if (tmpWord != NULL) {
        tmpWord->str = (char *)malloc((strlen(word)) + 1);
        strcpy(tmpWord->str, word);
        tmpWord->str[strlen(word)] = '\0';
        tmpWord->count = 1;
        tmpWord->next = NULL;
    }
    return tmpWord;
}

words *add_word(words **wordList, char *word) { 
    if (!*wordList) {
        return *wordList = create_words(word);
    }
    words *temp = *wordList;
    while (temp->next != NULL) {
        if (strcmp(temp->str, word) == 0) {
            temp->count = temp->count + 1;
            return *wordList;
        } else
            temp = temp->next;
    }
    words *tmpWord = create_words(word);
    if (NULL != tmpWord) { 
        temp->next = tmpWord;
    }
    return tmpWord;
}

int main(int argc, char *argv[]) {
    FILE *file;
    words *linkList = NULL;
    char *delim = ";. ,*\t\n";
    int ch = 0;
    int word = 1;
    int k = 0;
    char thisword[100];
    file = fopen(argv[1], "r");
    if (file == 0) {
        printf("ERROR!\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (strchr(delim, ch)) {
            if (word == 1) {
                word = 0;
                thisword[k] = '\0';
                if (add_word(&linkList, thisword)) {
                    k = 0;
                }
            }
        } else {
            word = 1;
            thisword[k++] = tolower(ch); 
        }
    }

    printf("\nWords in %s\n", argv[1]);
    int counted = 0;
    char* dots = ".";

    while (linkList != NULL) {
        counted = linkList->count;
        if(counted > 0 && strcmp(linkList->str,"the")!=0 && strcmp(linkList->str,"his") !=0 && strcmp(linkList->str,"hers") !=0 && strcmp(linkList->str,"so") !=0 && strcmp(linkList->str,"it")!=0 && strcmp(linkList->str,"is")!=0 && strcmp(linkList->str,"are") !=0 && strcmp(linkList->str,"their")!=0 && strcmp(linkList->str,"of")!=0 && strcmp(linkList->str,"or") !=0 && strcmp(linkList->str,"a") !=0 && strcmp(linkList->str,"to")!=0) {
            printf("%s", linkList->str);
            if(strlen(linkList->str)<40) {
                for(int i=0; i<(40-strlen(linkList->str)); i++) {
                    printf("%s", dots);
                }
            }
            printf("%d \n", linkList->count);
        } 
        linkList = linkList->next;
    }

    return 0;
}