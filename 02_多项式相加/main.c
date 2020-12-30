//
//  main.c
//  02_多项式相加
//
//  Created by 谢 on 2020/3/24.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* ptr;
};

typedef struct node Node;
typedef struct node* Nodeptr;

//本代码适用于项数较少的连续多项式
int main() {
    Nodeptr start1=NULL,start2=NULL,p=NULL,q=NULL;
    int m,n,i,val;
    scanf("%d%d",&m,&n);
    for (i=0; i<m; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        if (i==0) {
            start1=p;
        }
        else{
            q->ptr=p;
        }
        scanf("%d",&p->num);
        q=p;
        p->ptr=NULL;
    }
    for (i=0; i<n; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        if (i==0) {
            start2=p;
        }
        else{
            q->ptr=p;
        }
        scanf("%d",&p->num);
        q=p;
    }
    p=start1;
    q=start2;
    if (m>n) {
        while (p!=NULL&&q!=NULL) {
            p->num+=q->num;
            p=p->ptr;
            q=q->ptr;
        }
        p=start1;
        while (p!=NULL) {
            printf("%d ",p->num);
            p=p->ptr;
        }
    }
    else{
        while (p!=NULL&&q!=NULL) {
            q->num+=p->num;
            p=p->ptr;
            q=q->ptr;
        }
        p=start2;
        while (p!=NULL) {
            printf("%d ",p->num);
            p=p->ptr;
        }
    }
    printf("\n");
    return 0;
}
