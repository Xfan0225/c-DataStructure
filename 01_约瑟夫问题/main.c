//
//  main.c
//  01_约瑟夫问题
//
//  Created by 谢 on 2020/3/19.
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

int main() {
    int m,n,k,count=0,i,round=0;//n个人，从k开始报数，数到m出列
    Nodeptr p=NULL,q=NULL,start=NULL;
    scanf("%d%d%d",&n,&m,&k);
    for (i=1; i<=n; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        if (start==NULL) {
            start=p;
        }
        else{
            q->ptr=p;
        }
        p->num=i;
        q=p;
    }
    q->ptr=start;//创建为循环链表
    p=start;
    for (i=0; i<k-1; i++) {//推进到第k个人
        p=p->ptr;
    }
    round++;//第一个人计数器增加
    while (count<n) {//如果为n则说明所有人都被排除
        if (round<m) {//如果还没到第m个人
            p=p->ptr;//链表向前推进
            if (p->num>0) {
                round++;//如果是没有被排除的人，则计数器自加
            }
        }
        else{//如果已经到了第m个人
            printf("%d ",p->num);//输出该人的编号
            p->num=-1;//将该人编号设置为-1
            round=0;//置空统计数到第几个人的统计量
            count++;//排除人数增加1
        }
    }
    printf("\n");
    return 0;
}
