//
//  main.c
//  Data0603
//
//  Created by 谢 on 2020/4/25.
//  Copyright © 2020 谢. All rights reserved.
//

struct bitree{
    int num;
    struct bitree* lchild;
    struct bitree* rchild;
};

typedef struct bitree BITree;
typedef struct bitree* BITreeptr;

#include <stdio.h>
#include <stdlib.h>

void CreateSearchTree(int num,BITreeptr* head){//创建二叉查找树
    BITreeptr p=NULL,q=*head;
    p=(BITreeptr)malloc(sizeof(BITree));//先创造节点
    p->num=num;
    p->lchild=NULL;
    p->rchild=NULL;
    if (*head==NULL) {//如果头结点为空则储存头结点
        *head=p;
        return;
    }
    while (q!=NULL) {//否则从头对查找树进行遍历
        if (num<q->num) {//当比当前节点数小的时候
            if (q->lchild==NULL) {//假如当前节点左子树为空
                q->lchild=p;//则直接存入左子树
                break;
            }
            else{//否则继续遍历左子树
                q=q->lchild;
            }
        }
        else{//右子树的操作同理
            if (q->rchild==NULL) {
                q->rchild=p;
                break;
            }
            else{
                q=q->rchild;
            }
        }
    }
}

BITreeptr Search(int num,BITreeptr head){//查找节点的函数
    BITreeptr p=head;
    while (p!=NULL) {//当查找节点非空的时候
        if (p->num==num) {//假如找到
            return p;//则返回节点
        }
        if (p->num<num) {//假如当前节点的数字小
            p=p->rchild;//则查找当前节点的右子树
        }
        else if (p->num>num) {//假如大
            p=p->lchild;//则查找左子树
        }
    }
    return NULL;
}

void DeleteNode(int num,BITreeptr head){//删除节点的函数
    int flag=0,dir=0,count=0,flag1=0,flag2=0;
    BITreeptr p=head,q=NULL,r=head,n=NULL;
    while (flag==0) {//flag用于判断树中的该元素有无被全删完
        flag=1;
        p=head;
        while (p!=NULL) {//当查找节点非空的时候
            if (p->num==num) {//假如找到，开始向根节点遍历
                flag=0;
                count++;
                if (p->lchild!=NULL) {//假如左子树非空
                    q=p->lchild;//先记录左子树根节点，准备遍历
                    r=p;//遍历指针q的父节点先设置为p
                    while (q->rchild!=NULL) {//当未达到左子树的最右子树的时候
                        r=q;//进行遍历，直到最右，并且保存最右的父节点
                        q=q->rchild;
                        flag1=1;//表示存在右子树的标志
                    }
                    if (dir==1) {//将被删除节点的父节点链接到替换节点上
                        n->rchild=q;
                    }
                    else if(dir==2){
                        n->lchild=q;
                    }
                    if (flag1==0) {//假如不存在右子树的话，则替换为左子树的根节点
                        r->lchild=NULL;
                    }
                    else{//如果存在右子树的话，则右子树的左子树部分现在连接到被替换节点父节点的左子树上
                        r->rchild=q->lchild;
                    }
                    q->rchild=p->rchild;//新替换上的节点连接之前节点的左右子树
                    q->lchild=p->lchild;
                    flag1=0;
                }
                else if (p->rchild!=NULL){//如果只存在右子树的话操作方法类似
                    q=p->rchild;//q为替换节点，p为被替换节点，n为p的父节点
                    r=p;//r为q的父节点
                    while (q->lchild!=NULL) {
                        r=q;
                        q=q->lchild;
                        flag2=1;
                    }
                    if (dir==1) {
                        n->rchild=q;
                    }
                    else if(dir==2){
                        n->lchild=q;
                    }
                    if (flag2==0) {
                        r->rchild=NULL;
                    }
                    else{
                        r->lchild=q->rchild;
                    }
                    q->lchild=p->lchild;
                    q->rchild=p->rchild;
                    flag2=0;
                }
                else if(p->lchild==NULL&&p->rchild==NULL){
                    if (dir==1) {
                        n->rchild=NULL;
                    }
                    else if (dir==2){
                        n->lchild=NULL;
                    }
                }
                break;
            }
            else{
                if (p->num<num) {//假如当前节点的数字小
                    n=p;
                    p=p->rchild;//则查找当前节点的右子树
                    dir=1;
                }
                else if (p->num>num) {//假如大
                    n=p;
                    p=p->lchild;//则查找左子树
                    dir=2;
                }
            }
        }
    }
    printf("Delete %d times.\n",count);
}

int main() {
    BITreeptr head=NULL,find;
    int i,n,number;
    printf("Number of node:");
    scanf("%d",&n);
    printf("Delete number:");
    scanf("%d",&number);
    srand(3);
    for (i=0; i<n; i++) {//生成随机查找树
        CreateSearchTree(rand()%100, &head);
    }
    find=Search(number, head);//进行查找
    if (find!=NULL) {//如果找到则输出地址
        printf("Find!Adress:%p\n",find);
    }
    else{//找不到就报错
        printf("Not Find!\n");
        return 0;
    }
    DeleteNode(number, head);//先删除，删除后进行查找，检验删除效果
    find=Search(number, head);//进行查找
    if (find!=NULL) {//如果找到则输出地址
        printf("Find!Adress:%p\n",find);
    }
    else{//找不到就报错
        printf("Not Find!\n");
    }
    return 0;
}


