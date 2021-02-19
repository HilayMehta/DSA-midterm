#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    printf("Enter Size");
    scanf("%d", &(st->size));
    st->top = -1;
    st->s = (int*)malloc(st->size * sizeof(int));
}

void Display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void push(struct Stack *st,int x){
    if(st->top == st->size-1){
        printf("Stack Overflow \n");
    }
    else{
        (st->top)++;
        st->s[st->top] = x;
    }
}
int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack is Empty");
    }
    else{
        x = st->s[st->top--];
    }
    return x;
}

int peak(struct Stack st, int index){
    int x =-1;
    if(index > st.top){
        printf("Invalid Index");
    }
    else{
        x = st.s[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st){
    if(st.top == -1){
        return 1; //Stack Empty
    }
    return 0; //Not Empty
}
int isFull(struct Stack st){
    return st.top == st.size-1;
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.s[st.top];
    }
    return -1;
}
void main(){
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    printf("peak element at index %d %d \n",2, peak(st,2));

    Display(st);

    printf("pop %d \n",pop(&st));
    printf(" pop %d \n",pop(&st));
    printf("pop %d \n",pop(&st));
    printf("pop %d \n",pop(&st));
    printf("pop %d \n",pop(&st));



    Display(st);


}
