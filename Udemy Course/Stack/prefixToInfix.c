#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char *s;
};

void create(struct Stack *st){
    //printf("Enter Size");
    //scanf("%d", &(st->size));
    st->size = 100;
    st->top = -1;
    st->s = (char*)malloc(st->size * sizeof(char));
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

void push(struct Stack *st,char x)
{
    if(isFull(st)){
        printf("Stack Full");
    }
    st->top = st->top + 1;
    st->s[st->top] = x;
}
char pop(struct Stack *st)
{
    char x = '0';
    if(isEmpty(st)){
        printf("Stack is Empty");
    }
    else{
        x = st->s[st->top];
        st->top = st->top - 1;
    }
    return x;
}

char stackTop(struct Stack st){
    if(!isEmpty(&st)){
        return st.s[st.top];
    }
    return '0';
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

char *convertPreToInf(char *prefix){
    struct Stack st;
    create(&st);
    char *infix;
    infix = (char *)malloc((strlen(prefix) + 1 )*sizeof(char));
    int i = strlen(prefix)-1;
    int j = 0;
    //char x1[100],x2[100];
    //char res[100];
    while(i>=0){
        if(isOperand(prefix[i])){
            push(&st,prefix[i]);
            push(&st,' ');

        }
        else
        {

            for( j = st.top - 1;j>=0;j--){
                    //printf("%d",j);
                puts(infix);
                if(st.s[j]==' '){
                    //printf("%d",j);
                    st.s[j]= prefix[i];
                    //push(&st,prefix[i]);
                    break;
                }
            }
            //x1[0] = pop(&st);
            //x1[1] = prefix[i];
            //x2[0] = pop(&st);
            //strcat(x1,x2);
            //push(&st,x1);

        }
        i--;
    }
    int t;
    for(int j = st.top - 1,  t = 0;j>=0;j--,t++){

        infix[t] = pop(&st);
        //printf("answer is %c \n",infix[t]);
    }

    i = strlen(prefix);
    //printf("i is %d",i);
    infix[i]= '\0';
    return infix;
}
void main()
{
    char prefix[20] = "-+-/abcde";
    puts(prefix);
    char *inf;
    inf = convertPreToInf(prefix);
    for(int z = 0;inf[z] != '\0';z++){
        printf("%c",inf[z]);
    }

}
