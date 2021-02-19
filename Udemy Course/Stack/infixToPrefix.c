#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0; //To count the number '(' and ')' is occuring. because if '(' and ')' occurs then my postfix length decreases by 1. so keep a count of that i am using this count variable

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

char *convertInfixToPre(char *infix)
{

     struct Stack st;
     create(&st);
     char *postfix ;
     postfix =  (char *)malloc(sizeof(strlen(infix)+1));
     int i = strlen(infix) - 1;
     int j = strlen(infix) - 1;
     //int c = strlen(infix);
     while(i>=0){
            //printf("1");
        if(isOperand(infix[i])){

            postfix[j] = infix[i];
            i--;
            j--;
        }
        else if(infix[i]==')'){
                count++;
                push(&st,infix[i]);
                i--;

        }
        else if(infix[i] == '('){
                count++;
                    while(st.s[st.top]!= ')'){
                        postfix[j]=pop(&st);
                        j--;
                    }
                    char temp = pop(&st);
                    i--;

                    /*int temp ;
                    for(temp = i;temp>=0;temp--){
                        if(peak(st,temp) == '('){
                            postfix[j] = pop(&st)
                           }
                    }*/
                }
        else{
            if(prec(stackTop(st))>prec(infix[i])){
                postfix[j] = pop(&st);
                j--;
            }
            else{
                push(&st,infix[i]);
                i--;
            }
        }
     }
     while(!isEmpty(&st)){
        postfix[j] = pop(&st);
        j--;
     }
     postfix[strlen(infix)] = '\0';
     return postfix;

}
void main()
{
    char infix[20] = "a+b*c-d/e";//"a/b-(c+d)-e";
    puts(infix);
    //printf("infix length %d", strlen(infix));

    char *pf;

    pf = convertInfixToPre(infix);
    //printf("prefix length %d", strlen(pf));
    //printf("%c", pf[0]);
    for(int z = count;pf[z] != '\0';z++){
        printf("%c",pf[z]);
    }


}
