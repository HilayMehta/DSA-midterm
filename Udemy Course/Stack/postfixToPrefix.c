#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char s[100][100];
};

void create(struct Stack *st){
    //printf("Enter Size");
    //scanf("%d", &(st->size));
    st->size = 100;
    st->top = -1;
    //st->s = (char*)malloc(st->size * sizeof(char));
}

int isFull(struct Stack *st){
    if(st->top==st->size - 1){
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct Stack *st){
    if(st->top == -1){
        return 1;
    }
    else
        return 0;
}

void push(struct Stack *st,char x[])
{
    if(isFull(st)){
        printf("Stack Full");
    }
    st->top = st->top + 1;
    strcpy(st->s[st->top],x);
    //st->s[st->top] = x;
}
char *pop(struct Stack *st)
{
    char *x;
    x= (char *)malloc(100*sizeof(char));

    if(isEmpty(st)){
        printf("Stack is Empty");
    }
    else{
            strcpy(x, st->s[st->top]);
        //x = st->s[st->top];
        st->top = st->top - 1;
    }
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



char *convertPostfixToPrefix(char *postfix){
    struct Stack st;
    create(&st);
    char *prefix;
    prefix = (char *)malloc((strlen(postfix) + 1 )*sizeof(char));
    int i = 0;
    int j = 0;
    //char x1[100],x2[100];
    //char res[100];
    while(postfix[i]!='\0'){
            char *a1,*a2;
            a1 = (char *)malloc(100*sizeof(char));
            a2= (char *)malloc(100*sizeof(char));
        if(isOperand(postfix[i])){
                char temp2[100];
                temp2[0]= postfix[i];
                temp2[1] = '\0';
            push(&st,temp2);
            //push(&st,' ');
        }
        else
        {   char temp[100];
            char prefix[100];
            char op = postfix[i];
            temp[0] = op;
            temp[1]='\0';
            strcpy(prefix,temp);
            a1 = pop(&st); //b
            a2 = pop(&st); //a
            strcat(prefix,a2);
            strcat(prefix,a1);
            push(&st, prefix);


        }
        i++;
    }
    prefix = pop(&st);
    return prefix;
}
void main()
{
    char postfix[20] = "ab/c-d+e-";
    puts(postfix);
    char *pre;
    pre = convertPostfixToPrefix(postfix);
    for(int z = 0;pre[z] != '\0';z++){
        printf("%c",pre[z]);
    }

}

