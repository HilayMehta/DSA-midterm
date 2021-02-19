#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct{
     int top ;
     int *s;
     int SIZE;
 }STACK;

 void create(STACK *st,int size)
 {
     st->top = -1;
     //printf("%d", st->top);
     st->SIZE = size;
     //printf("test");
     st->s = (int *)malloc(100*sizeof(st->SIZE));

 }

void push(STACK *st,int item)
{
   // printf("test");
    if(st->top == st->SIZE -1)
    {
        printf("Stack is Full");
    }
   // printf("%d", st->top);
    st->top = st->top + 1;
    //printf("test in push");
    //printf("%d", st->top);
    st->s[st->top] = item;
    //printf("test in push");
    //printf("%d", st->s[st->top]);
    //printf("test in push");
}

int pop(STACK *st)
{
    char x = ' ';
    if(st->top ==-1){
        printf("Stack is Empty");
        return x;
    }
    x = st->s[st->top];
    st->top --;
    return x;
}

void display(STACK *st){
    for(int i = st->top; i>=0;i--)
    {
        printf("%c ", st->s[i]);
    }
    printf("\n");
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


int evalpref(STACK *st, char *prefix){
   // int i = strlen(prefix) - 1;

    for(int i = strlen(prefix) - 1 ; i>=0;i--)
    {

        if(isOperand(prefix[i]))
        {
           // printf("%d", prefix[i] - '0');
            push(st, prefix[i]-'0');
            //printf("%d", prefix[i] - '0');
        }
        else{
            int x = pop(st);
            int y = pop(st);
            int r;
            switch(prefix[i]){
                case '+': r = x + y;
                    push(st,r);
                    break;
                case '-': r = x-y;
                    push(st,r);
                    break;
                case '*': r = x*y;
                    push(st,r);
                    break;
                case '/': r = x/y;
                    push(st,r);
                    break;
            }
        }
    }
    return pop(st);


}
void main()
{
    STACK st;
    create(&st,10);
    st.top = -1;
    //push(&st,1);
    printf("Enter the prefix string \n");
    char *prefix;
    prefix = (char *)malloc(100*sizeof(char));
    gets(prefix);
    printf("Evaluated prefix = %d \n", evalpref(&st,prefix));


}

/*MITEmployee(int a,int i, int s, int y){
    super(a,i,s);
    year  =y;
}
MITEmployee E[] = new MITEmployee[5];
E[0] = new MITEmployee(19,190905316,40000, 5);
E[0] = new MITEmployee(19,190905317,50000, 5);*/
