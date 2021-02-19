#include<stdio.h>
#include<stdlib.h>


struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{

    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s)
{

    printf("Enter Dimension");
    scanf("%d %d", &s->m,&s->n);
    printf("Number of non zero elements");
    scanf("%d", &s->num);
    s->e = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter Non zero Elements");
    for(int i=0;i<s->num;i++)
    {
        scanf("%d%d%d", &s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void display(struct Sparse s){
    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.e[k].i && j== s.e[k].j)
                printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void main()
{
    struct Sparse s;
    create(&s);
    display(s);


}
