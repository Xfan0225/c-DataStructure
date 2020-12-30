//
//  main.c
//  Data0602
//
//  Created by 谢 on 2020/4/16.
//  Copyright © 2020 谢. All rights reserved.
//

struct tree{
    int num;
    struct tree* lchild;
    struct tree* rchild;
};

struct trtree{
    int num;
    struct trtree* lchild;
    struct trtree* rchild;
    struct trtree* parent;
};

typedef struct tree BITree;
typedef struct tree* BITreeptr;
typedef struct trtree TRTree;
typedef struct trtree* TRTreeptr;

#include <stdio.h>
#include <stdlib.h>

BITreeptr CreateTree(int num,int tag,BITreeptr* head,BITreeptr q);
TRTreeptr CreateTRTree(int num,int tag,TRTreeptr* head,TRTreeptr q);
BITreeptr ReverseTree (BITreeptr head);

void SearchTRTree(TRTreeptr head,int depth);
void SearchBITree(BITreeptr head,int depth);
void CountNode(BITreeptr head);
void PrintTree();

int ans[100][100],count[100],depth_ans=0;//设置全局变量方便统计

int main() {
    BITreeptr head=NULL,q=NULL;
    //TRTreeptr head=NULL,q=NULL;
    int i=1,n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {//随机生成二叉树
        q=CreateTree(i,rand()%2, &head, q);
    }
    SearchBITree(head, 0);
    PrintTree();
    ReverseTree(head);
    SearchBITree(head, 0);
    printf("\nReversed Tree:\n");
    PrintTree();
    /*
    for (i=0; i<n; i++) {
        q=CreateTRTree(i, rand()%2, &head, q);
        count[i]=0;
    }
    SearchTRTree(head, 0);
    for (i=0; i<depth_ans+1; i++) {
        printf("Depth:%d ",i);
        for (j=0; j<count[i]; j++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
     */
    return 0;
}

BITreeptr CreateTree(int num,int tag,BITreeptr* head,BITreeptr q){
    BITreeptr p,move;//生成二叉树的函数
    p=(BITreeptr)malloc(sizeof(BITree));//首先用malloc函数开辟空间
    p->lchild=NULL;
    p->rchild=NULL;
    p->num=num;
    if (*head==NULL) {//假如还没有头节点则保存头结点
        *head=p;
    }
    else if (q->lchild==NULL&&tag==0) {//假如左子树为空切且入左边
        q->lchild=p;//则直接存入即可
        return q;//返回前一个节点
    }
    else if (q->lchild!=NULL&&tag==0){//假如左子树满但存入左边
        move=*head;//从头开始寻找第一个为空的左子树
        while (move->lchild!=NULL) {
            move=move->lchild;
        }
        move->lchild=p;
        return move;//返回前一个节点
    }
    else if (q->rchild==NULL&&tag==1) {//右子树操作同上
        q->rchild=p;
        return q;
    }
    else if (q->rchild!=NULL&&tag==1){
        move=*head;
        while (move->rchild!=NULL) {
            move=move->rchild;
        }
        move->rchild=p;
        return move;
    }
    return p;//返回头结点
}

TRTreeptr CreateTRTree(int num,int tag,TRTreeptr* head,TRTreeptr q){
    TRTreeptr p,move;//生成三叉链表二叉树的函数
    p=(TRTreeptr)malloc(sizeof(TRTree));//首先用malloc函数开辟空间
    p->lchild=NULL;
    p->rchild=NULL;
    p->parent=NULL;
    p->num=num;
    if (*head==NULL) {//假如还没有头节点则保存头结点
        *head=p;
    }
    else if (q->lchild==NULL&&tag==0) {//假如左子树为空切且入左边
        q->lchild=p;//则直接存入即可
        p->parent=q;
        return q;//返回前一个节点
    }
    else if (q->lchild!=NULL&&tag==0){//假如左子树满但存入左边
        move=*head;//从头开始寻找第一个为空的左子树
        while (move->lchild!=NULL) {
            move=move->lchild;
        }
        move->lchild=p;
        p->parent=move;
        return move;//返回前一个节点
    }
    else if (q->rchild==NULL&&tag==1) {//右子树操作同上
        q->rchild=p;
        p->parent=q;
        return q;
    }
    else if (q->rchild!=NULL&&tag==1){
        move=*head;
        while (move->rchild!=NULL) {
            move=move->rchild;
        }
        move->rchild=p;
        p->parent=move;
        return move;
    }
    return p;//返回头结点
}

void CountNode(BITreeptr head){
    BITreeptr p=head,ls[100];
    int ans[3],i=0;
    for (i=0; i<3; i++) {
        ans[i]=0;
    }
    i=0;
    while (p!=NULL||i!=0) {//非递归中序遍历二叉树
        while (p!=NULL) {//假如没到最左端左子树
            ls[i]=p;//入栈
            i++;
            p=p->lchild;
        }
        if (i!=0) {//假如到了之后且栈非空
            i--;//返回栈顶
            if (ls[i]->lchild==NULL&&ls[i]->rchild==NULL) {//判断该节点的度，并储存
                ans[0]+=1;
            }
            else if((ls[i]->lchild!=NULL&&ls[i]->rchild==NULL)||(ls[i]->lchild==NULL&&ls[i]->rchild!=NULL)){
                ans[1]+=1;
            }
            else if(ls[i]->lchild!=NULL&&ls[i]->rchild!=NULL){
                ans[2]+=1;
            }
            p=ls[i]->rchild;//开始遍历右子树
        }
    }
    printf("deg0:%d deg1:%d deg2:%d\n",ans[0],ans[1],ans[2]);
}

BITreeptr ReverseTree (BITreeptr head){
    BITreeptr p=head,ls[100],val;
    int i=0;
    while (p!=NULL||i!=0) {//非递归中序遍历二叉树
        while (p!=NULL) {//假如没到最左端左子树
            ls[i]=p;//入栈
            i++;
            p=p->lchild;
        }
        if (i!=0) {//假如到了之后且栈非空
            i--;
            if (ls[i]->lchild!=NULL&&ls[i]->rchild!=NULL) {//进行节点交换
                val=ls[i]->lchild;//假如可以进行交换，则交换左右子树
                ls[i]->lchild=ls[i]->rchild;
                ls[i]->rchild=val;
            }
            p=ls[i]->rchild;//继续遍历右子树
        }
    }
    return head;
}

void SearchTRTree(TRTreeptr head,int depth){//按层次遍历算法，本质是前序遍历算法
    if (depth>depth_ans) {//统计树的深度
        depth_ans=depth;
    }
    ans[depth][count[depth]]=head->num;//提取树的信息（访问根节点）
    count[depth]++;//该层的节点个数自加
    if (head->lchild!=NULL) {//然后访问左子树
        SearchTRTree(head->lchild, depth+1);
    }
    if (head->rchild!=NULL) {//再访问右子树
        SearchTRTree(head->rchild, depth+1);
    }
}

void SearchBITree(BITreeptr head,int depth){//按层次遍历算法，本质是前序遍历算法
    if (depth>depth_ans) {//统计树的深度
        depth_ans=depth;
    }
    ans[depth][count[depth]]=head->num;//提取树的信息（访问根节点）
    count[depth]++;//该层的节点个数自加
    if (head->lchild!=NULL) {//然后访问左子树
        SearchBITree(head->lchild, depth+1);
    }
    if (head->rchild!=NULL) {//再访问右子树
        SearchBITree(head->rchild, depth+1);
    }
}

void PrintTree(){//输出树并且重置统计数组
    int i,j;
    for (i=0; i<depth_ans+1; i++) {
        printf("Depth:%d ",i);
        for (j=0; j<count[i]; j++) {
            printf("%d ",ans[i][j]);
            ans[i][j]=0;
        }
        count[i]=0;
        printf("\n");
    }
}
