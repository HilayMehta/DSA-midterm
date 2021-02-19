#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear = NULL;
void enqueue(int x){
   // printf("1");
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(rear ==NULL){
            front = rear = t;
            rear->next = front;
        }
        else{
            rear->next = t;
            rear = t;
            rear->next = front;
        }
//printf("%d", rear->data);
}

int dequeue(){
    int x = -1;
    struct Node *t;
    t = front;
    if(front == NULL){
        printf("Empty \n");
    }
    else if(rear == front){
            x = front->data;
        front = rear = NULL;
        free(t);
    }
    else{
        x = front->data;
        front = front->next;
        rear->next = front;   // this steps because of circular queues
        //t =front;
        //front = front->next;
        free(t);
    }
    return x;
}

void Display(){
    //printf("1");
    struct Node *p = front;
    if(front == NULL){
        printf("Empty \n");
    }
    else{
        while(p->next != front){
                //printf("1");
            printf("%d ", p->data);
            p=p->next;
        }
        printf("%d",p->data);
    }

}

void main(){
    enqueue(1);
    enqueue(2);
    Display();
    printf("\n%d",dequeue());
}
