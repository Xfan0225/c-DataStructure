//
//  main.c
//  05_稀疏矩阵的加法
//
//  Created by 谢 on 2020/4/9.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct tuple{
    int num;
    int x;
    int y;
};//采用结构tuple的形式表示三元组

typedef struct tuple Tuple;
typedef struct tuple* Tupleptr;

void PrintVertex(Tupleptr*,int,int,int);
Tupleptr* SortTuple(Tupleptr*,int);
int AddVertex(Tupleptr*,int,Tupleptr*,int);

int main() {
    int n0,n1,i,div_x,div_y;
    Tupleptr ls0[100],p,ls1[100];//用两个指针数组来储存三元组
    printf("Please Input Diversion of Matrix:\n");
    scanf("%d%d",&div_x,&div_y);
    printf("Please Input Number of 1st Tuple:\n");
    scanf("%d",&n0);//n为稀疏矩阵非0元素的个数，div_x,y为行,列数
    if (div_y*div_x<n0) {
        printf("Error:Too Many Elements!\n");
        return 0;
    }
    printf("Please Input 1st Tuple:\n");
    for (i=0; i<n0; i++) {//三元组的输入
        p=(Tupleptr)malloc(sizeof(Tuple));
        scanf("%d%d%d",&p->num,&p->x,&p->y);
        ls0[i]=p;
    }
    printf("Please Input Number of 2nd Tuple:\n");
    scanf("%d",&n1);//n为稀疏矩阵非0元素的个数，div_x,y为行,列数
    if (div_y*div_x<n1) {
        printf("Error:Too Many Elements!\n");
        return 0;
    }
    printf("Please Input 1st Tuple:\n");
    for (i=0; i<n1; i++) {//三元组的输入
        p=(Tupleptr)malloc(sizeof(Tuple));
        scanf("%d%d%d",&p->num,&p->x,&p->y);
        ls1[i]=p;
    }
    n0=AddVertex(ls0, n0, ls1, n1);
    printf("Ans:\n");
    PrintVertex(ls0, n0, div_x, div_y);
    return 0;
}

Tupleptr* SortTuple(Tupleptr* ls,int n){
    Tupleptr p=NULL;//对3元组的下标进行从小到大的冒泡排序，以便输出矩阵
    int i,j;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (ls[j]->x>ls[j+1]->x) {
                p=ls[j];
                ls[j]=ls[j+1];
                ls[j+1]=p;
            }
            else if(ls[j]->x==ls[j+1]->x&&ls[j]->y>ls[j+1]->y){
                p=ls[j];
                ls[j]=ls[j+1];
                ls[j+1]=p;
            }
        }
    }
    return ls;
}

void PrintVertex(Tupleptr* ls,int n,int div_x,int div_y){
    int i,j,count=0;
    ls=SortTuple(ls, n);//首先将三元组从小到大排序，方便输出
    for (i=0; i<div_x; i++) {
        for (j=0; j<div_y; j++) {//假如该输出的坐标与三元组坐标相同
            if (i==ls[count]->x-1&&j==ls[count]->y-1) {
                printf("%d ",ls[count]->num);//则输出三元组的数
                count++;//并且三元组输出计数器自加
            }
            else{//否则就输出0
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int AddVertex(Tupleptr*ls0,int n0,Tupleptr *ls1,int n1){
    SortTuple(ls0, n0);SortTuple(ls1, n1);//先排序，方便后续的加法运算
    int i,j;
    for (i=0; i<n1; i++) {//对第二个序列作为相加序列遍历
        for (j=0; j<n0; j++) {//每一次相加遍历一次第一个序列
            if (ls1[i]->x==ls0[j]->x&&ls1[i]->y==ls0[j]->y) {//如果相同的话直接相加即可
                ls0[j]->num+=ls1[i]->num;
                break;
            }
            else if (ls1[i]->x<ls0[j]->x||(ls1[i]->x==ls0[j]->x&&ls1[i]->y<ls0[j]->y)) {
                ls0[n0]=ls1[i];//如果不同的话就将原来没有的接在被加数组的末尾
                n0++;//并且将被加数组的长度+1
                SortTuple(ls0, n0);//然后进行排序
                break;
            }
        }
    }
    return n0;
}
