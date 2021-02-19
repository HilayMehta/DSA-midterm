#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char capital(char *str,int i ){
    if(str[i] == '\0')
    {
        return ' ';
    }
    if(str[i] >64 && str[i]<=91){
        return str[i];
    }
    capital(str,i+1);
}

void main(){
    char *str;
    str = (char *)malloc(100*sizeof(char));
    printf("Enter string \n");
    gets(str);
    printf("First capital letter is %c", capital(str,0));

}
