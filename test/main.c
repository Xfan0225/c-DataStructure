//
//  main.c
//  test
//
//  Created by 谢 on 2020/6/13.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node Node;
typedef struct node* Nodeptr;

struct node * exam20(struct node *Ha, struct node *Hb)
{   struct node *Hc, *d,  *p,  *q;
    p = Ha;      q = Hb;
    Hc =  (struct node *)malloc(sizeof(struct node));
    d = Hc;
    while (p!=0 && q!=0)
    {    if (p->data == q->data)
        {   d->link = p;  d = p;  p = p->link;
            while (p!=0 && p->data == q->data)  p = p->link;
q = q->link;          }
        else if (p->data < q->data)
        {    d->link = p;   d=p; p = p->link;         }
        else
        {    d->link = q;  d=q; q = q->link;         }
    }
    if (p!=0)   d->link=p;   else   d->link = q;
    p = Hc->link;
    while (p!=0)  {     printf("%d， ",p->data);        p=p->link;    }
    return(Hc);
}

void Delete(Nodeptr Ha,Nodeptr Hb, Nodeptr Hc){
    Nodeptr p=Ha,q=Hb,r=Hc,p1=NULL;
    int num,flag=0;
    while (p!=NULL) {
        num=p->data;
        while (q!=NULL&&q->data<num) {
            q=q->link;
        }
        while (r!=NULL&&r->data<num) {
            r=r->link;
        }
        if (q!=NULL&&r!=NULL) {
            if (r->data==num&&q->data==num) {
                flag=1;
                if (p!=Ha) {
                    p1->link=p->link;
                }
                else{
                    Ha=p->link;
                }
            }
        }
        if (flag==0) {
             p1=p;
        }
        p=p->link;
        flag=0;
    }
    p=Ha;
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->link;
    }
}

int count=0;
void CountNum(int i,int* BITree,int depth,int k){
    if (BITree[i]!=0&&depth<=k) {
        if (depth==k) {
            count++;
        }
        else if (BITree[2*i]==0&&BITree[2*i+1]==0) {
            count++;
        }
        else{
            CountNum(2*i, BITree, depth+1, k);
            CountNum(2*i+1, BITree, depth+1, k);
        }
    }
}

int visited[100],Order[100];
void DPS(int node,int ls[100][100],int num,int count){
    int i=0;
    if (count==0) { //如果输入的是第一个元素，则先存入已访问的元素中
        visited[node]=1;
        Order[count]=node+1;
        count++;
    }
    if (count==num) { //如果全部遍历过，则输出遍历结果
        for (i=0; i<num-1; i++) {
            printf("%d->",Order[i]);
        }
        printf("%d\n",Order[i]);
    }
    else{ //否则当前节点的邻接矩阵的所在行进行遍历，寻找下一个可行节点
        for (i=0; i<num; i++) {
            if (ls[node][i]==1&&visited[i]==0) {//如果未被访问且可达
                Order[count]=i+1;//将该节点存入访问队列
                visited[i]=1;//更改访问指标
                DPS(i, ls, num, count+1);//继续递归深度遍历
            }
        }
    }
}

//认为树的节点从数组的1号位置开始，depth代表目前遍历的深度，k为数的深度，i为当前根节点
int main() {
    int A[6]={12,12,30,40,50,55},B[7]={12,12,20,40,40,50,60},C[7]={12,20,30,40,50},BITree[9]={0,1,2,3,4,5,0,6};
    int i,j,ls[100][100];
    srand(3);
    Nodeptr s1=NULL,s2=NULL,s3=NULL,p,q=NULL;
    for (i=0;i<6;i++) {    //创建链表a
        p=(Nodeptr)malloc(sizeof(Node));
        p->data=A[i];
        p->link=NULL;
        if (s1==NULL) {
            s1=p;
        }
        else{
            q->link=p;
        }
        q=p;
    }
    for (i=0;i<7;i++) {    //创建链表a
        p=(Nodeptr)malloc(sizeof(Node));
        p->data=B[i];
        p->link=NULL;
        if (s2==NULL) {
            s2=p;
        }
        else{
            q->link=p;
        }
        q=p;
    }
    for (i=0; i<5; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        p->data=C[i];
        p->link=NULL;
        if (s3==NULL) {
            s3=p;
        }
        else{
            q->link=p;
        }
        q=p;
    }
    //Delete(s3, s1, s2);
    //CountNum(1,BITree,1,3);
    for (i=0; i<4; i++) {
        visited[i]=0;
        Order[i]=0;
        for (j=0; j<4; j++) {
            if (i!=j) {
                ls[i][j]=1;
            }
            else if (i>2&&j>2){
                ls[i][j]=0;
            }
            printf("%d ",ls[i][j]);
        }
        printf("\n");
    }
    DPS(0, ls, 4, 0);
    //printf("%d",count);
    return 0;
    
}

