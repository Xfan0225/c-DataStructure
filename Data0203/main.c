//
//  main.c
//  Data0203
//
//  Created by 谢 on 2020/3/16.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* ptr;
};

struct BInode{//建立双向链表的结构体
    int num;
    struct BInode* front;
    struct BInode* back;
};

typedef struct node Node;
typedef struct node* Nodeptr;

typedef struct BInode BINode;
typedef struct BInode* BINodeptr;

Nodeptr CreateNode(int,int);
BINodeptr CreateBINode(int,int);
Nodeptr* SplitNode(Nodeptr);
BINodeptr DeleteBINode(BINodeptr,int);
int IsInList(int*,int,int);
Nodeptr DeleteNode(Nodeptr);

int main() {
    Nodeptr start,p,q,*ls,p1,p2;
    int i,n0,n1;
    start=CreateNode(0,5);
    printf("Initial Node:");
    p=start;
    while (p!=NULL) {
        printf("%d ",p->num);
        p=p->ptr;
    }
    printf("\n");
    p=DeleteNode(start);
    printf("Delete Node:");
    while (p!=NULL) {
        printf("%d ",p->num);
        p=p->ptr;
    }
    printf("\n");
    
    /*
    ls=SplitNode(start);
    p1=ls[0]->ptr;
    p2=ls[1]->ptr;
    n0=ls[0]->num;
    n1=ls[1]->num;
    printf("Odd Node:");
    for (i=0; i<n0; i++) {
        printf("%d ",p1->num);
        p1=p1->ptr;
    }
    printf("\n");
    printf("Even Node:");
    for (i=0; i<n1; i++) {
        printf("%d ",p2->num);
        p2=p2->ptr;
    }
    printf("\n");
    */
    
    /*
    BINodeptr start,p,q,*ls,p1,p2;
    int i,n=10,n1;
    start=CreateBINode(-5, 5);
    start=DeleteBINode(start, n);
    p=start;
    printf("Delete %d:\n",n);
    printf("Positive Sequence:");
    while (p->back!=NULL) {//正序遍历
        printf("%d ",p->num);
        p=p->back;
    }
    printf("%d ",p->num);
    printf("\n");
    printf("Negative Sequence:");
    while (p!=NULL) {//逆序遍历
        printf("%d ",p->num);
        p=p->front;
    }
    printf("\n");
     */
}

Nodeptr CreateNode(int start,int end){//创建start-end的连续链表
    Nodeptr head=NULL,p=NULL,q=NULL;
    int i,j,k;
    for (k=0; k<2; k++) {
        for (i=start; i<=end; i++) {
            for (j=0; j<3; j++) {
                p=(Nodeptr)malloc(sizeof(Node));
                if (head==NULL) {
                    head=p;
                }
                else{
                    q->ptr=p;
                }
                p->num=i;
                p->ptr=NULL;
                q=p;
            }
        }
    }
    /*
    p=(Nodeptr)malloc(sizeof(Node));//创建头结点
    p->ptr=head;
    p->num=end-start+1;
    return p;
     */
    return head;
}

BINodeptr CreateBINode(int start, int end){//建立双向链表
    BINodeptr head=NULL,p=NULL,q=NULL;
    int i;
    for (i=start; i<=end+5; i++) {
        p=(BINodeptr)malloc(sizeof(BINode));
        p->num=i;
        if (i>end) {
            p->num=end-i;
        }
        if (head==NULL) {//对于表头节点的前序节点置空
            head=p;
            head->front=NULL;
            p->back=NULL;
        }
        else{//对于所有节点前序节点的back指向该节点，该节点的front指向前序节点
            q->back=p;
            p->front=q;
            p->back=NULL;
        }
        q=p;
    }
    return head;
}

Nodeptr* SplitNode(Nodeptr start){
    Nodeptr ls[2],q0=NULL,q1=NULL;
    int i,n=start->num;
    start=start->ptr;
    for (i=0; i<2; i++) {//创建并置空一个节点数组,作为循环链表的头结点
        ls[i]=(Nodeptr)malloc(sizeof(Node));
        ls[i]->num=0;
        ls[i]->ptr=(Nodeptr)malloc(sizeof(Node));
    }
    for (i=1; i<=n; i++,start=start->ptr) {
        if (i%2==1) {//如果是奇链表
            if (i==1) {//如果是头结点则存入节点数组
                ls[0]->ptr=start;
                q0=ls[0]->ptr;
            }
            else{//如果不是头结点则接在链表后面
                q0->ptr=start;
                q0=start;
            }
            ls[0]->num++;//奇链表计数器自加
        }
        else if (i%2==0){
            if (i==2) {//对于偶链表的处理o同上
                ls[1]->ptr=start;
                q1=ls[1]->ptr;
            }
            else{
                q1->ptr=start;
                q1=start;
            }
            ls[1]->num++;
        }
    }
    q0->ptr=ls[0]->ptr;//将链表尾部接在链表头，构成循环链表
    q1->ptr=ls[1]->ptr;
    return ls;//返回节点数组
}

BINodeptr DeleteBINode(BINodeptr start, int del){
    BINodeptr p=start,q=NULL;
    while (p!=NULL) {//采用正序遍历的方式遍历双向链表
        if (p->num==del) {//当找到需要删除元素时
            if (q!=NULL) {//如果不为第一个节点（前序为空）
                if (p->back!=NULL) {//如果不为最后一个节点（后续为空）
                    q->back=p->back;//前序节点指向本节点后续节点
                    p->back->front=q;//后继节点指向本节点前序节点
                }
                else{//如果为最后一个节点
                    q->back=NULL;//直接将前序节点的后续置空
                }
            }
            else {//如果为第一个节点
                p->back->front=NULL;//将后续节点的前序置空
                start=p->back;//将头结点设置为后续节点
            }
        }
        q=p;
        p=p->back;
    }
    return start;
}

Nodeptr DeleteNode(Nodeptr head){
    int ls[1000],count=0;//创建一个数组储存出现过的数字
    Nodeptr p=head,q=NULL;
    while (p!=NULL) {
        if (IsInList(ls, p->num, count)) {//用函数判断该数字是否在数组中
            if (q!=NULL) {//如果前驱结点不为空则之间跳过该重复节点
                q->ptr=p->ptr;
            }
            else if (q==NULL){//如果前驱节点为空则直接改变头结点
                head=p->ptr;
            }
            p=p->ptr;//不移动前驱节点，仅将当前节点后移
        }
        else{//如果数字未出现过
            ls[count]=p->num;//则将该数字存入数组
            count++;//并且增加数组长度
            q=p;//并且移动当前节点与前驱节点
            p=p->ptr;
        }
    }
    return head;//返回链表的头结点
}

int IsInList(int* ls,int num,int lenth){//查找数字是否在数组中的函数
    int i;
    if (lenth==0) {//如果数组长度为0直接认为不在数组中
        return 0;
    }
    for (i=0; i<lenth; i++) {//如果不为0则查找是否重复
        if (ls[i]==num) {
            return 1;//如果重复返回1
        }
    }
    return 0;//如果没找到重复则返回0
}
