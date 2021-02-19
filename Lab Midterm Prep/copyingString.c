#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void copy(char *str1, char *str2, int i){
    if(str1[i] == '\0'){
        return;
    }
    else{
//printf("1");
        str2[i] = str1[i];
        i= i+1;
        copy(str1,str2,i);
    }
}

void main(){
        char *str1;
        str1 = (char *)malloc(100*sizeof(char));
        printf("Enter main string \n");
        gets(str1);
        //puts(str1);
        char *str2;
        str2 = (char *)malloc(100*sizeof(char));
        copy(str1,str2,0);
        printf("Copied string is \n");
        puts(str2);
}
