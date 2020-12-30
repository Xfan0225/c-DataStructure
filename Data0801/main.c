//
//  main.c
//  Data0801
//
//  Created by 谢 on 2020/5/19.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* ptr;
};

typedef struct node Node;
typedef struct node* Nodeptr;

void SwitchSort(int ls[100],int n){//选择排序
    int i,j,place=0,min=ls[0],val,CountCompare=0,CountSwitch=0;
    for (i=0; i<n; i++) {
        for (j=i; j<n; j++) {
            if (ls[j]<min) {//降序排序
                min=ls[j];//如果最小的话
                place=j;//就记录位置
            }
            CountCompare++;//记录比较次数
        }
        val=ls[i];//进行交换
        ls[i]=ls[place];
        ls[place]=val;
        CountSwitch++;//记录交换次数
        min=ls[i+1];//将最小值重置为未交换的首元素
    }
    printf("Switch Sorted List:");//输出排序结果以及交换，比较次数
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
    printf("Switch:%d,Compare:%d\n",CountSwitch,CountCompare);
}

void BubbleSort(int ls[100],int n){//冒泡排序算法
    int i,val,flag=1,CountSwitch=0,CountCompare=0,m=n;
    while (flag==1) {//假如有交换发生，则继续冒泡
        flag=0;//先把标志重置
        for (i=0; i<m-1; i++) {//然后进行冒泡排序
            if (ls[i]>ls[i+1]) {//把大的往上浮
                val=ls[i];
                ls[i]=ls[i+1];
                ls[i+1]=val;
                CountSwitch++;//交换次数自加
                flag=1;//并且更改产生交换的flag
            }
            CountCompare++;
        }
        m--;//将最上层元素排除
    }
    printf("Bubble Sorted List:");
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
    printf("Switch:%d,Compare:%d\n",CountSwitch,CountCompare);
}

void LinerInsertSort(int ls[100],int n){//线性插入排序
    int i,j,k,Sorted[100],CountSwitch=0,CountCompare=0,flag=0;
    for (i=0; i<n; i++) {//第一层循环遍历原列表所有元素
        for (j=0; j<i; j++) {//第二层循环对排序后列表进行插入
            CountCompare++;
            if (ls[i]<Sorted[j]) {//假如发现可插入点
                flag=1;//则更改插入过的标志
                for (k=i; k>j; k--) {//集体后移
                    Sorted[k]=Sorted[k-1];
                    CountSwitch++;
                }
                Sorted[j]=ls[i];//插入
                break;//终止循环
            }
        }
        if (flag==0) {//假如没插入过，说明是最大元素
            Sorted[i]=ls[i];//直接接在队尾
        }
        flag=0;//重置插入标志
    }
    printf("LinerInsert Sorted List:");
    for (i=0; i<n; i++) {
        printf("%d ",Sorted[i]);
    }
    printf("\n");
    printf("Switch:%d,Compare:%d\n",CountSwitch,CountCompare);
}

void ChainBubbleSort(Nodeptr ls,int n){
    int flag=1;
    Nodeptr p=ls,q=NULL,val=NULL;
    while (flag==1) {
        flag=0;//先更改遍历标志
        p=ls;//每次都从头遍历
        while(p->ptr!=NULL) {
            if (p->num>p->ptr->num) {//链表的交换
                val=p->ptr->ptr;//首先记录一下当前节点的后继的后继
                if (p==ls) {//假如是头节点
                    ls=p->ptr;//则储存头结点为后继（交换后就为后继）
                    p->ptr=val;//将当前节点的后继节点设置为先前的标记
                    ls->ptr=p;//头节点的后继节点则为当前节点
                    q=ls;//前一节点则为头结点
                }
                else{//如果不是头结点
                    q->ptr=p->ptr;//前一节点的后继为当前节点的后继
                    q=p->ptr;//当前节点的前节点为当前节点的后继
                    p->ptr->ptr=p;//当前节点后继的后继为本节点
                    p->ptr=val;//当前节点的后继为记录的节点
                }
                flag=1;//将已交换标志更改
            }
            else{//如果没出现交换
                q=p;//则储存当前节点的前节点
                p=p->ptr;//推进节点
            }
        }
    }
    p=ls;
    while (p!=NULL) {
        printf("%d ",p->num);
        p=p->ptr;
    }
    printf("\n");
}

void ShellSort(int ls[100],int n){
    int i,j,k,d=n,val,flag=1;
    while (d>1) {//内嵌冒泡排序
        d=d/2;
        for (i=0; i<d; i++) {//首先对折半的d进行遍历，方便后续进行移动
            while (flag==1) {
                flag=0;//先重置标志
                for (j=0; j<n/d-1; j++) {//然后对子序列做冒泡排序
                    if (ls[j*d+i]>ls[(j+1)*d+i]) {
                        flag=1;
                        printf("%d<->%d:",ls[j*d+i],ls[(j+1)*d+i]);//输出交换步骤
                        val=ls[j*d+i];
                        ls[j*d+i]=ls[(j+1)*d+i];
                        ls[(j+1)*d+i]=val;
                        for (k=0; k<n; k++) {//输出交换后的列表
                            printf("%d ",ls[k]);
                        }
                        printf("\n");
                    }
                }
            }
            flag=1;//重置标志
        }
    }
}

void QuickSort(int ls[100],int left,int right){
    int i,k,n=11,last,val;
    if (left<right) {//假如左边比右边小
        last=left;//将最后交换值设为最左，最后last所指即为该元素所在位置
        for (i=left+1; i<right; i++) {//从最后交换值的后一个开始遍历
            if (ls[i]<ls[left]) {//假如该值比最左元素要小
                last++;//将最后交换值点向后移动一个（多了一个小于最初交换值的元素），并且跟该最小元素进行互换
                val=ls[last];
                ls[last]=ls[i];
                ls[i]=val;
                if (i!=last) {//并且假如不是无效交换，则输出交换顺序
                    printf("%d<->%d:",ls[i],ls[last]);//输出交换步骤
                    for (k=0; k<n; k++) {//输出交换后的列表
                        printf("%d ",ls[k]);
                    }
                    printf("\n");
                }
            }
        }
        val=ls[left];//最后将最左元素放到正确的位置
        ls[left]=ls[last];
        ls[last]=val;
        if (last!=left) {
            printf("%d<->%d:",ls[last],ls[left]);//输出交换步骤
            for (k=0; k<n; k++) {//输出交换后的列表
                printf("%d ",ls[k]);
            }
            printf("\n");
        }
        QuickSort(ls, left, last-1);//将正确位置的左右元素继续递归
        QuickSort(ls, last+1, right);
    }
}

int main() {
    int i,ls[100],n=100;
    //Nodeptr p=NULL,q=NULL,head=NULL;
    int testls[11]={58,43,72,90,12,35,68,65,28,95,20};
    for (i=0; i<n; i++) {
        ls[i]=rand()%100;
    }
    /*
    SwitchSort(ls, n);
    BubbleSort(ls, n);
    LinerInsertSort(ls, n);
    
    for (i=0; i<n; i++) {
        p=(Nodeptr)malloc(sizeof(Node));
        p->num=rand()%100;
        p->ptr=NULL;
        if (head==NULL) {
            head=p;
        }
        else{
            q->ptr=p;
        }
        q=p;
    }
    ChainBubbleSort(head, n);
    */
    //ShellSort(testls, 11);
    QuickSort(testls, 0, 11);
    return 0;
}
