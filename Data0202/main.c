//
//  main.c
//  data0202
//
//  Created by 谢 on 2020/3/9.
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

void delnode(Nodeptr,int);
Nodeptr appendNode(Nodeptr,int);
Nodeptr reverseNode(Nodeptr);
Nodeptr joinNode(Nodeptr,Nodeptr);

int main(){
    Nodeptr start=NULL,q=NULL,p=NULL,a=NULL,b=NULL;
    int ls[10]={1,2,2,2,1,1,2,3,4,5},n=10,i,j,append=-1;
    for (j=5;j<n;j++) {    //创建链表a
        p=(Nodeptr)malloc(sizeof(Node));
        p->num=j*2;
//        p->num=ls[j];
        p->nodeptr=NULL;
        if (start==NULL) {
            start=p;
        }
        else{
            q->nodeptr=p;
        }
        q=p;
    }
    a=start;start=NULL;
    printf("Node a:");
    for (p=a; p!=NULL; p=p->nodeptr) {
        printf("%d ",p->num);
    }
    printf("\n");
    for (j=-5;j<0;j++) {    //创建链表b
            p=(Nodeptr)malloc(sizeof(Node));
            p->num=j*3;
            p->nodeptr=NULL;
            if (start==NULL) {
                start=p;
            }
            else{
                q->nodeptr=p;
            }
            q=p;
        }
    b=start;
    printf("Node b:");
    for (p=b; p!=NULL; p=p->nodeptr) {
        printf("%d ",p->num);
    }
    printf("\n");
//    delnode(a, 0);
//    a=appendNode(a, append);
//    a=reverseNode(a);
    a=joinNode(a,b);
    printf("Join Node:");
    for (p=a; p!=NULL; p=p->nodeptr) {
        printf("%d ",p->num);
    }
    printf("\n");
}

void delnode(Nodeptr H,int b){
    Nodeptr p=H,q=H;
    for (p=H; p!=NULL; p=p->nodeptr) {
        if (p->num==b) {//发现删除元素时
            if (p==H) {//如果是在头结点
                H=H->nodeptr;//则将头结点向后推一位
            }
            else{
                q->nodeptr=p->nodeptr;//否则将上一个节点的下一位链接到本节点的下一位
            }
        }
        else{
            q=p;//如果没发现删除元素，则将本节点作为下一个节点的前节点储存
        }
    }
    printf("DEL num %d :",b);
    for (p=H; p!=NULL; p=p->nodeptr) {
        printf("%d ",p->num);
    }
    printf("\n");
}

Nodeptr appendNode(Nodeptr H,int b){
    Nodeptr p=H,q=H,n=NULL;
    for (p=H; p!=NULL; p=p->nodeptr) {
        if (p->num==b) {//如果链表中已经存在该元素，程序结束
            break;
        }
        if (p->num>b) {//遇到表中大于插入元素的第一个元素的时候，即为插入点
            if (p==H) {//如果是头指针，则创建新的头指针，将其插入头部
                H=(Nodeptr)malloc(sizeof(Node));
                H->num=b;
                H->nodeptr=p;
            }
            else{//如果是在中间，则将其在中间插入
                n=(Nodeptr)malloc(sizeof(Node));
                n->num=b;
                q->nodeptr=n;
                n->nodeptr=p;
            }
            break;//插入之后即可结束循环
        }
        if (p->nodeptr==NULL&&p->num<b) {//如果是在表尾部，则在尾部插入
            n=(Nodeptr)malloc(sizeof(Node));
            n->num=b;
            p->nodeptr=n;
            n->nodeptr=NULL;
        }
        q=p;//如果还不到插入点，则储存本节点，作为下一个节点的前节点使用
    }
    return H;//返回头指针
}

Nodeptr reverseNode(Nodeptr H){
    Nodeptr p=H,q=H,n=H;
    for (p=H; p!=NULL; p=q) {//采用p=q的递进方式避免因为p的link改变带来的影响
        q=p->nodeptr;//q为p的下一位指针
        if (p!=H) {//如果不是头指针
            p->nodeptr=n;//则将当前节点的后继指向前驱节点，达到翻转的目的
        }
        else{
            p->nodeptr=NULL;//如果是头指针，则翻转后为尾部，将其后继节点置空
        }
        n=p;//用n储存当前节点，作为下一步的前驱节点使用
    }
    return n;//因为执行完p=q之后p已经为NULL，所以返回p的前驱n
}

Nodeptr joinNode(Nodeptr a,Nodeptr b){
    Nodeptr p=a,q=b,r=a,n=b,m=b;
    for (p=a; p!=NULL; p=p->nodeptr) {//对表a进行遍历
        while (q->num<p->num) {//遇到表b中的可插入项时
            n=q->nodeptr;//先储存好表b的后继节点
            if (p==a) {//如果b的头结点最小，则直接将a头结点更改
                a=q;
                while (q->num<p->num) {//并且直接移动到b即将大于a头节点的节点
                    m=q;
                    q=q->nodeptr;
                    if (q->nodeptr==NULL) {//h假如移动到末尾还未找到该节点
                        q->nodeptr=p;//说明b恒比a小，直接将a头结点接到b尾部
                        return a;//返回a头结点
                    }
                }
                m->nodeptr=p;
                n=q;
            }
            else{//不然就把b的节点插入a中
                r->nodeptr=q;
                q->nodeptr=p;
            }
            q=n;//后移表b节点
        }
        r=p;//储存表a当前节点
    }
    if (q!=NULL) {//如果a遍历完成后b表未遍历完
        r->nodeptr=q;//直接将未遍历完的b接在a的结尾
    }
    return a;
}
