//
//  main.c
//  Data0701
//
//  Created by 谢 on 2020/4/29.
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

void CountDeg(Nodeptr ls[100],int n){
    int InDeg[100],OutDeg[100],i=0,CountOut=0;
    Nodeptr p;
    for (i=0; i<n; i++) {//首先置空统计表
        InDeg[i]=0;
        OutDeg[i]=0;
    }
    for (i=0; i<n; i++) {//循环遍历邻接表
        p=ls[i];//首先从表头开始
        while (p!=NULL) {//同时统计入度和初度
            CountOut++;
            InDeg[p->num-1]++;//如果出现在邻接表中，则入度+1
            p=p->ptr;
        }
        OutDeg[i]=CountOut;//然后邻接表的大小就是初度
        CountOut=0;//置空统计量
    }
    printf("In Degree:");//输出入度和出度
    for (i=0; i<n; i++) {
        printf("%d ",InDeg[i]);
    }
    printf("\nOut Degree:");
    for (i=0; i<n; i++) {
        printf("%d ",OutDeg[i]);
    }
    printf("\n");
}

void search(Nodeptr ls[100],int start,int end){
    Nodeptr stack[100],p=ls[start-1];
    int i=1,visited[100],j,flag=0;
    for (j=0; j<100; j++) {
        visited[j]=0;
    }
    visited[start]=1;//从start开始查找，start先入栈
    while (flag==0&&i>0) {//假如栈非空且为找到的时候
        while (p!=NULL) {//对邻接表内进行查找
            while (visited[p->num]==1) {//先找未访问节点
                p=p->ptr;
                if (p==NULL) {//假如到头，则直接break
                    break;
                }
            }
            if (p==NULL) {//假如到头，直接break
                break;
            }
            else if (p->num==end){//如果找到了下一点，且是终点
                stack[i]=p;
                flag=1;//修改标志，直接break
                break;
            }
            else{//如果找到了下一点，但不是终点
                visited[p->num]=1;//标记寻找
                stack[i]=p;i++;//入栈下一查找节点
                p=ls[p->num-1];//从下一点开始查找
            }
        }
        if (i==1) {
            break;
        }
        else if (flag!=1) {
            visited[stack[i-1]->num]=0;
            p=stack[i-1]->ptr;
            i--;
        }
    }
    if (flag==1) {
        printf("Find way!:%d->",start);
        for (j=1; j<i; j++) {
            printf("%d->",stack[j]->num);
        }
        printf("%d\n",end);
    }
    else
        printf("No way!\n");
}

void dps(Nodeptr ls[100],int head){
    Nodeptr stack[100],p=ls[head-1];
    int i=1,visited[100];//用visited储存是否遍历
    stack[0]=p;visited[head]=1;//设置栈顶元素
    printf("%d ",head);//直接输出第一个遍历的元素
    while (i>0) {//当遍历层数大于0的时候
        while (p!=NULL) {//假如没遍历到末尾
            while (visited[p->num]==1) {//假如遍历过的话
                p=p->ptr;//就跳过节点
                if (p==NULL) {//假如遍历到末尾，则直接break
                    break;
                }
            }
            if (p==NULL) {
                break;
            }
            printf("%d ",p->num);//找到节点之后就输出
            visited[p->num]=1;//并且将visited修改
            stack[i]=p;i++;//节点存入栈
            p=ls[p->num-1];//遍历从该节点开始遍历下一个节点
        }
        i--;
        p=stack[i];//深度遍历完之后，开始出栈
    }
}

int main() {
    Nodeptr ls[100],p=NULL,q=NULL;
    int i,n,inp,start,end,head;
    scanf("%d",&n);//输入节点个数
    for (i=0; i<n; i++) {
        ls[i]=NULL;//先置空节点链表
        while (1) {//输入节点的相邻节点，以-1结束
            p=(Nodeptr)malloc(sizeof(Node));
            p->ptr=NULL;
            scanf("%d",&inp);
            if (inp==-1) {
                break;
            }
            p->num=inp;
            if (ls[i]==NULL) {//当表头为空的时候
                ls[i]=p;//存入表头
            }
            else{
                q->ptr=p;//否则接到后面
            }
            q=p;
        }
    }
    //printf("DPS Start from?:");
    //scanf("%d",&head);//以head为初始节点
    //dps(ls,head);//进行深度遍历
    //printf("Please Input Start and End:\n");
    //scanf("%d%d",&start,&end);
    //search(ls, start, end);
    //printf("\n");
    CountDeg(ls,n);
    return 0;
}

/*
8
2 3 -1
1 4 5 -1
1 6 7 -1
2 8 -1
2 8 -1
3 8 -1
3 8 -1
4 5 6 7 -1
 */
/*
5
2 -1
3 -1
4 5 -1
1 -1
-1
 */
