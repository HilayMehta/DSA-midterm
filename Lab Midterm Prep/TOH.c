#include<stdio.h>
#include<stdlib.h>

void TOH(int n, char source, char temp,char destination){
    if(n==1)
    {
        printf(" Move Disk from %c to %c", source, destination);
        return;
    }

    TOH(n-1,source,destination,temp);
    printf("Move disk from %c to %c", source,destination);
    TOH(n-1,temp,source,destination);
}

void main(){
    int n;
    printf("Enter the size of discs \n");
    scanf("%d", &n);
    TOH(n,'A','B','C');
}
