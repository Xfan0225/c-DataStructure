//
//  main.c
//  02_2 稀疏多项式相加
//

//  Created by 谢 on 2020/3/24.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int exp;
    int num;
    struct node* ptr;
};

typedef struct node Node;
typedef struct node* Nodeptr;

int main() {
    int m,n,i,flag=0;//m,n为多项式项的个数
    Nodeptr head1=NULL,head2=NULL,p=NULL,q=NULL,p1=NULL,q1=NULL,val=NULL;//head为多项式头节点
    scanf("%d%d",&m,&n);
    printf("Please enter 1st multinomial\n");
    for (i=0; i<m; i++) {//输入第一个多项式
        p=(Nodeptr)malloc(sizeof(Node));
        if (head1==NULL) {
            head1=p;
        }
        else{
            q->ptr=p;
        }
        q=p;
        scanf("%d%d",&p->exp,&p->num);
        p->ptr=NULL;
    }
    q=NULL;
    printf("Please enter 2nd multinomial\n");
    for (i=0; i<n; i++) {//输入第二个多项式
        p=(Nodeptr)malloc(sizeof(Node));
        if (head2==NULL) {
            head2=p;
        }
        else{
            q->ptr=p;
        }
        q=p;
        scanf("%d%d",&p->exp,&p->num);
        p->ptr=NULL;
    }
    p=head1;
    p1=head2;
    while (p!=NULL) {//将第一个多项式的链表作为结果，将第二个多项式的项插入第一个链表中
        val=p1;//储存第二个多项式的头结点
        while (p1->exp>p->exp) {//将第二个多项式移动到第一个不大于第一个多项式节点的位置
            q1=p1;
            p1=p1->ptr;
            flag=1;
            if (p1==NULL) {
                break;
            }
        }
        if (flag==1) {//假如发生了移动
            if (p==head1) {//假如第一个多项式仍处于头结点，则更改头结点
                head1=val;
                q1->ptr=p;
            }
            else{//否则将大于第一个多项式的整段插入
                q->ptr=val;
                q1->ptr=p;
            }
        }
        if (p==NULL||p1==NULL) {//假如有任意一个多项式到达结尾则break循环
            break;
        }
        if (p1->exp==p->exp) {//假如发现相等的项则进行相加操作
            p->num+=p1->num;
            q1=p1;
            p1=p1->ptr;
        }
        q=p;//第一个多项式进行移动并且将flag重置
        p=p->ptr;
        flag=0;
        if (p==NULL||p1==NULL) {
            break;
        }
    }
    if (p1!=NULL) {//假如第二个多项式还未遍历完则直接接到第一个多项式的末尾
        q->ptr=p1;
    }
    p=head1;
    printf("Ans:\n");
    while (p!=NULL) {
        printf("%d %d\n",p->exp,p->num);
        p=p->ptr;
    }
    return 0;
}
