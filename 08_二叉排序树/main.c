//
//  main.c
//  08_二叉排序树
//
//  Created by 谢 on 2020/4/28.
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

void CreateSearchTree(int num,BITreeptr* head){//创建二叉排序树
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

void SearchTree(BITreeptr p){//用递归方法中序遍历二叉树
    if (p==NULL) {
        return;//为空时停
    }
    SearchTree(p->lchild);//先访问左节点
    printf("%d ",p->num);//访问中序节点
    SearchTree(p->rchild);//再访问右节点
}
int main() {
    BITreeptr head=NULL;
    int n,number;
    while (1) {//从键盘获取输入
        scanf("%d",&number);
        if (number==-1) {
            break;
        }
        else{//来创建二叉搜索树
            CreateSearchTree(number, &head);
        }
    }
    SearchTree(head);//查找二叉搜索树
    printf("\n");
    return 0;
}
