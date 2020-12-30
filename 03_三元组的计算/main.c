//
//  main.c
//  03_三元组的计算
//
//  Created by 谢 on 2020/4/5.
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
Tupleptr* ReverseVertex(Tupleptr*,int);

int main() {
    int n,i,div_x,div_y;
    Tupleptr ls[100],p;//用一个指针数组来储存三元组
    printf("Please Input Number of Tuple:\n");
    scanf("%d",&n);//n为稀疏矩阵非0元素的个数，div_x,y为行,列数
    printf("Please Input Diversion of Vertex:\n");
    scanf("%d%d",&div_x,&div_y);
    if (div_y*div_x<n) {
        printf("Error:Too Many Elements!\n");
        return 0;
    }
    printf("Please Input Tuple:\n");
    for (i=0; i<n; i++) {//三元组的输入
        p=(Tupleptr)malloc(sizeof(Tuple));
        scanf("%d%d%d",&p->num,&p->x,&p->y);
        ls[i]=p;
    }
    printf("\nInput Vertex:\n");
    PrintVertex(ls,n,div_x,div_y);
    printf("Inverse Vertex\n");
    ReverseVertex(ls,n);
    PrintVertex(ls,n,div_y,div_x);
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

Tupleptr* ReverseVertex(Tupleptr* ls,int n){
    int i,val;//将三元组中的x,y坐标交换完成转置
    for (i=0; i<n; i++) {
        val=ls[i]->x;
        ls[i]->x=ls[i]->y;
        ls[i]->y=val;
    }
    return ls;
}
