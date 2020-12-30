//
//  main.c
//  Data0702
//
//  Created by 谢 on 2020/5/13.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    int count;
    struct node* ptr;
};

typedef struct node Node;
typedef struct node* Nodeptr;

Nodeptr ls[100];

void CountDeg(int n){
    int InDeg[100],i=0;
    Nodeptr p;
    for (i=0; i<n; i++) {//首先置空统计表
        InDeg[i]=0;
    }
    for (i=0; i<n; i++) {//循环遍历邻接表
        p=ls[i]->ptr;//首先从表头开始
        while (p!=NULL) {//统计入度
            InDeg[p->num-1]++;//如果出现在邻接表中，则入度+1
            p=p->ptr;
        }
    }
    for (i=0; i<n; i++) {
        ls[i]->count=InDeg[i];
    }
}

void SearchAOV(int n){
    Nodeptr stack[100],p=NULL;
    int count=0,i,find[100],flag=0;
    while (1) {
        for (i=0; i<n; i++) {//首先将入度为0的定点存入栈
            if (ls[i]->count==0&&find[i]!=1) {
                stack[count++]=ls[i];
                find[i]=1;//对遍历过的定点进行标记
                flag=1;
            }
        }
        if (count==0) {//如果栈空则说明输出完成
            break;
        }
        printf("%d ",stack[count-1]->num);//输出栈顶顶点
        p=stack[count-1]->ptr;//对栈顶元素的联通顶点进行遍历
        while (p!=NULL) {//将其联通顶点的入度-1（视同删除该顶点）
            ls[p->num-1]->count--;
            p=p->ptr;
        }
        count--;//出栈
    }
    if (flag==0) {
        printf("Not VOA!");
    }
    printf("\n");
}

int main() {
    int n,i,inp;
    Nodeptr p=NULL,q=NULL;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        ls[i]=p;//先创建表头节点,用于储存入度信息
        p->ptr=NULL;
        p->num=i+1;
        q=p;
        while (1) {//输入节点的相邻节点，以-1结束
            p=(Nodeptr)malloc(sizeof(Node));
            p->ptr=NULL;
            scanf("%d",&inp);
            if (inp==-1) {
                break;
            }
            p->num=inp;
            q->ptr=p;
            q=p;
        }
    }
    CountDeg(n);//统计入度
    SearchAOV(n);//拓扑排序VOA
    return 0;
}

/*
7
3 4 -1
4 5 -1
6 7 -1
7 -1
7 -1
-1
-1
 
7
3 4 -1
4 5 -1
4 6 7 -1
1 7 -1
7 -1
-1
-1
 
 */
