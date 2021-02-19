#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int size;
    int top;
    char s[100][100];
}STACK;

void create(STACK *st){
    st->top =-1;
    st->size = 100;
}

void push(STACK *st, char str[]){
    if(st->top == st->size - 1){
        printf("Stack is full \n");
        return;
    }
    st->top++;
    strcpy(st->s[st->top],str);
    //st->s[top] = str;
}

 char* pop(STACK *st){
    char *x;
    x= (char *)malloc(100*sizeof(char));
    //x = NULL;
    if(st->top == -1){
        printf("Stack is Empty \n");
        return;
    }
    x = st->s[st->top];
    st->top --;
    return x;
}

int isOperand(char x)
{
    if(x == '+'|| x =='-'|| x == '*'|| x=='/' || x=='('|| x==')'){
        return 0;
    }
    else
        return 1;
}
int prec(char x)
{
    if(x == '+'|| x =='-'){
        return 1;
    }
    else if(x == '*'|| x =='/'){
        return 2;
    }
    else
        return 0;
}

char* convertPrefixtoInfix(char *prefix,STACK *st){
    char *infix;
    infix = (char *)malloc((strlen(prefix) + 1 )*sizeof(char));
    int i = strlen(prefix);
    //int j = 0;
    while(i>=0){
        char *a1,*a2;
        a1 = (char *)malloc(100*sizeof(char));
        a2= (char *)malloc(100*sizeof(char));
        if(isOperand(prefix[i])){
                char temp2[100];
                temp2[0]= prefix[i];
                temp2[1] = '\0';
            push(st,temp2);
        }
        else{

            a1 = pop(st); //b
            //strcat(infix,a1);
            char temp[100];
            //char p[100];
            char op = prefix[i];
            temp[0] = op;
            temp[1]='\0';
            strcat(a1,temp);
            //strcpy(infix,temp);
            a2 = pop(st); //a
            strcat(a1,a2);
            //strcat(prefix,a1);
            push(st, a1);

            }
            i--;
    }
    infix = pop(st);
    return infix;
}
void main(){
    STACK st;
    create(&st);
    char prefix[20] = "-*+4325";
    puts(prefix);
    char *pre;
    pre = convertPrefixtoInfix(prefix,&st);
    for(int z = 0;pre[z] != '\0';z++){
        printf("%c",pre[z]);
    }
}
