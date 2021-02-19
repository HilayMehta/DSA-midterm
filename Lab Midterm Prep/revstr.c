#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void revstr(char *str,int i,int j){
   if(i == strlen(str)/2)
   {
       return;
   }
   char temp;
   temp = str[i];
   str[i] = str[j];
   str[j] = temp;
   revstr(str,i+1,j-1);

}

void main()
{
    char *str;
    str = (char *)malloc(100*sizeof(char));
    printf("Enter string \n");
    gets(str);
    revstr(str,0,strlen(str)-1);
    puts(str);

}
