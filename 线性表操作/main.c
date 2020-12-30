//
//  main.c
//  元素删除
//
//  Created by 谢 on 2020/3/3.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* nodeptr;
};

typedef struct node Node;
typedef struct node* Nodeptr;

//为了简化测试数据的使用，所有函数均用void方法定义，并且在函数内进行输出。
void del(int,int,int*);
void change(int,int*);
void insert(int,int*,int,int*,int);
void delji(int,int*);
void delnode(Nodeptr,int);
void appendNode(Nodeptr,Nodeptr);
void AppendSortedNode(Nodeptr,Nodeptr,Nodeptr);

int main() {
    int ls[100]={1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1},add[100]={1,1,1,2,2,2,3,3,3},n=10,j;
    Nodeptr start=NULL,q=NULL,p,a=NULL,b=NULL,c=NULL;
    for (j=1;j<=n;j++) {    //创建链表a
        p=(Nodeptr)malloc(sizeof(Node));
        p->num=j;
        p->nodeptr=NULL;
        if (start==NULL) {
            start=p;
        }
        else{
            q->nodeptr=p;
        }
        q=p;
    }
    a=start;
    for (j=n+10; j>0; j--) {    //创建链表b
        p=(Nodeptr)malloc(sizeof(Node));
        p->num=j;
        p->nodeptr=NULL;
        if (b==NULL) {
            b=p;
        }
        else{
            q->nodeptr=p;
        }
        q=p;
    }
    del(1, 20, ls);
    change(20, ls);
    insert(20, ls, 9, add, 5);
    delji(20, ls);
    delnode(start,5);
    appendNode(a,b);
    AppendSortedNode(a, b, c);
    return 0;
}

void del(int num,int lenth,int* ls){    //作业1：
    int i,j;
    for (i=0; i<lenth; i++) {
        if (ls[i]==num) {//找到删除元素时
            lenth--;//将表长-1
            for (j=i; j<lenth-1; j++) {//表从后一点开始整体向前挪动一位
                ls[j]=ls[j+1];
            }
        }
    }
    printf("del %d ls:",num);
    for (i=0; i<lenth; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
}

void change(int lenth,int *ls){ //作业2
    int i,lsnew[20],ji[20],ou[20],countji=0,countou=0;
    for (i=0; i<lenth; i++) {
        if (ls[i]%2==0) {
            ou[countou]=i;
            countou++;
        }
        else if (ls[i]%2==1){
            ji[countji]=i;
            countji++;
        }
    }
    for (i=0; i<lenth; i++) {
        if (i<countji) {
            lsnew[i]=ls[ji[i]];
        }
        else{
            lsnew[i]=ls[ou[i-countji]];
        }
    }
    printf("change ls:");
    for (i=0; i<lenth; i++) {
        printf("%d ",lsnew[i]);
    }
    printf("\n");
}

void insert(int lenth,int* ls,int ins_lenth, int* ins_ls,int place){    //作业3
    int i;
    for (i=lenth; i>=place; i--) {
        ls[ins_lenth+i]=ls[i];
    }
    for (i=place; i<place+ins_lenth; i++) {
        ls[i]=ins_ls[i-place];
    }
    printf("Insert list:");
    for (i=0; i<lenth+ins_lenth; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
}

void delji(int lenth,int* ls){  //作业4
    int i,j,count=0;
    for (i=lenth-1; i>=0; i--) {
        if (i%2==0) {
            for (j=i; j<lenth-count; j++) {
                ls[j]=ls[j+1];
            }
            count++;
        }
    }
    printf("delji:");
    for (i=0; i<lenth-count; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
}

void delnode(Nodeptr start,int del){    //作业5
    Nodeptr i=start,j=start;
    while (i!=NULL) {
        if (i->num==del) {
            j->nodeptr=i->nodeptr;
        }
        j=i;
        i=i->nodeptr;
    }
    printf("delnode:");
    for (i=start;i!=NULL; i=i->nodeptr) {
        printf("%d ",i->num);
    }
    printf("\n");
}

void appendNode(Nodeptr a,Nodeptr b){   //作业6
    Nodeptr new=NULL,p=NULL,q=NULL;
    while (a!=NULL&&b!=NULL) {
        p=(Nodeptr)malloc(sizeof(Node));
        if (new==NULL) {
            new=p;
        }
        else{
            q->nodeptr=p;
        }
        p->num=a->num;
        a=a->nodeptr;
        q=p;
        p=(Nodeptr)malloc(sizeof(Node));
        q->nodeptr=p;
        p->num=b->num;
        b=b->nodeptr;
        p->nodeptr=NULL;
        q=p;
    }
    if (a==NULL) {
        while (b!=NULL) {
            p=(Nodeptr)malloc(sizeof(Node));
            q->nodeptr=p;
            p->num=b->num;
            b=b->nodeptr;
            p->nodeptr=NULL;
            q=p;
        }
    }
    else if (b==NULL){
        while (a!=NULL) {
            p=(Nodeptr)malloc(sizeof(Node));
            q->nodeptr=p;
            p->num=a->num;
            a=a->nodeptr;
            p->nodeptr=NULL;
            q=p;
        }
    }
    printf("AppendNode:");
    for (p=new; p!=NULL; p=p->nodeptr) {
        printf("%d ",p->num);
    }
    printf("\n");
}

void AppendSortedNode(Nodeptr a,Nodeptr b,Nodeptr c){   //作业7
    Nodeptr start=NULL,q=NULL,i;
    int flag=0;
    while (a!=NULL) {
        c=(Nodeptr)malloc(sizeof(Node));
        if (start==NULL) {
            start=c;
        }
        else{
            q->nodeptr=c;
        }
        c->num=a->num;
        c->nodeptr=NULL;
        q=c;
        a=a->nodeptr;
    }
    while (b!=NULL) {
        i=start;
        c=(Nodeptr)malloc(sizeof(Node));
        while (i!=NULL) {
            if (b->num<i->num) {
                c->num=b->num;
                q->nodeptr=c;
                c->nodeptr=i;
                flag=1;
                break;
            }
            q=i;
            i=i->nodeptr;
        }
        if (flag==0) {  //以防出现的数是现存链表中最大的
            q->nodeptr=c;
            c->num=b->num;
            c->nodeptr=NULL;
        }
        b=b->nodeptr;
        flag=0;
    }
    i=start;
    printf("AppendSortedNode:");
    while (i!=NULL) {
        printf("%d ",i->num);
        i=i->nodeptr;
    }
    printf("\n");
}
