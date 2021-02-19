#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack is Full \n");
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }

}
int pop(){
    int x = -1;
    if(top == NULL){
        return x;
    }
    else{
        struct Node *p ;
        p = (struct Node *)malloc(sizeof(struct Node));
        p = top;
        x = p->data;
        top = p->next;
        p->next = NULL;
        free(p);
        return x;
    }
}
void Display(){
    struct Node *p;
    p = top;
    while(p!= NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void main()
{
    push(10);
    push(20);
    push(30);

    Display();
    printf(" pop: %d", pop());
    Display();

}
