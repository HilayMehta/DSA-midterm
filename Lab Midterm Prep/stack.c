#include<stdio.h>
#include<stdlib.h>

 typedef struct{
     int top ;
     char *s;
     int SIZE;
 }STACK;

 void create(STACK *st,int size)
 {
     st->top =-1;
     st->SIZE = size;
     //printf("test");
     st->s = (char *)malloc(100*sizeof(st->SIZE));

 }

void push(STACK *st,int item)
{
   // printf("test");
    if(st->top == st->SIZE -1)
    {
        printf("Stack is Full");
    }
    st->top++;
    st->s[st->top] = item;
    //printf("%d", st->s[st->top]);
    //printf("test");
}

char pop(STACK *st)
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
void main()
{
    STACK st;
    create(&st,10);
    push(&st,'a');
    push(&st,'b');
    push(&st,'c');
    display(&st);
    printf("Popped %c \n");
    pop(&st);
    display(&st);

}
