#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palin(char *str, int i, int j){
  //int p =1; //palindrome
  if(i == strlen(str)/2){
    return 1;
  }

  if(str[i] != str[j]){
    //p=0;
    //printf("test");
    return 0;
  }
  else{
    palin(str,i+1,j-1);
  }

}

void main()
{
    char *str;
    str = (char *)malloc(100*sizeof(char));
    printf("Enter string \n");
    gets(str);
    int j = strlen(str);
    if(palin(str, 0,j-1)){
        printf("Palindrome");
    }
    else{
        printf("Not a palindrome \n");
    }
}
