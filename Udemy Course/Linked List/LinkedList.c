#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first= NULL;

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    last = first;

    for(i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        RDisplay(p->next);

    }
}

int count(struct Node *p){
    int l = 0;
    while(p!=NULL){
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node *p){
    if(p!=NULL){
        return Rcount(p->next)+1;
    }
    else
        return 0;
}

int sum(struct Node *p){
    int s = 0;
    while(p!=NULL){

        s= s+ p->data;
        p = p->next;
    }
    return s;
}
int Rsum(struct Node *p){
    if(p!= NULL){

        return p->data + Rsum(p->next);
    }
    else
        return 0;
}
int max(struct Node *p){
    int m = p->data;

    while(p!=NULL){

        if(p->data > m){
            m = p->data;
        }
        p=p->next;
    }
    return m;
}

void main(){
    int a[5]= {3,4,5,6,7};
    create(a,5);
    //Display(first);
    //RDisplay(first);
    //count(first);
    printf("%d", max(first));
}
