/*#Gilberto Rogel García A01630171*/
/*Exercise 1-23. Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly. C comments do not nest.*/
#include <stdio.h>

void removeComments(char *a)
{
    int i,j;
    for(i=j=0; a[j] ;  )
    {
        if(a[j]=='/' && a[j+1] && a[j+1]=='/')
            for(j+=2; a[j] && a[j++]!='\n';  )	;
        else if(a[j]=='/' && a[j+1] && a[j+1]=='*')
            for(j+=2; a[j] && a[++j] && (a[j-1]!='*' || a[j]!='/' || !j++); );
        else
            a[i++]=a[j++];
    }
    a[i]='\0';
}

int main() 
{
    char charArray[]="/*blalalala(esto no)*/ <Imprime esto> /*hola(esto no) //esto tampoco";
    removeComments(charArray);
    printf(charArray);
    return 0;
}