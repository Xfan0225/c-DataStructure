//
//  main.c
//  Data0802
//
//  Created by 谢 on 2020/5/27.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void make(int*,int,int);
void Change(int*,int,int);
void HeapSort(int*,int);
void MergeSort(int*,int);
void Merge(int*,int*,int,int,int);

void make(int ls[100] ,int i,int j){
    int val;//交换函数
    val=ls[i];
    ls[i]=ls[j];
    ls[j]=val;
}

void Change(int ls[100],int n,int i){
    int j;
    while (i<n/2) {
        if (ls[i]>ls[i*2+1]||ls[i]>ls[i*2+2]) {
            if (ls[i*2+1]<ls[i*2+2]) {//假如左右节点有比根节点大
                make(ls,i,i*2+1);//将最大的节点与根节点交换
            }
            else{
                make(ls,i,i*2+2);
            }
            for (j=0; j<n; j++) {//输出交换后的堆
                printf("%d ",ls[j]);
            }
            printf("\n");
        }
        if (i!=0) {//继续看下一个节点是否满足堆条件
            i*=2;
        }
        else{
            i++;
        }
    }
}

void HeapSort(int ls[100],int n){
    int i,j;
    for (i=n/2; i>=0; i--) {
        Change(ls, n, i);//构造初始堆
    }
    /*
    for (j=0; j<n; j++) {//输出交换后的堆
        printf("%d ",ls[j]);
    }
    printf("\n");
    for (i=n-1; i>=1; i--) {//从后往前依次构造堆
        Change(ls, i, 0);
        if (i==1&&ls[i]<ls[0]) {//避免无效交换
             make(ls, i, 0);
        }
        else if (i!=1){
             make(ls, i, 0);
        }
        for (j=0; j<n; j++) {//输出交换后的堆
            printf("%d ",ls[j]);
        }
        printf("\n");
    }
     */
}

void Merge(int ls[100],int Merged[100],int lenth,int start,int end){
    int i=start,j=start+lenth,count=start;//count表示排序后列表的指针
    while (count<end) {//当没排到队尾的时候
        if (ls[i]>ls[j]) {//升序排序
            Merged[count]=ls[j];
            j++;
        }
        else{
            Merged[count]=ls[i];
            i++;
        }
        count++;
        if (i==start+lenth) {//假如一个序列排到末尾
            for (i=j; i<end; i++) {//其他的直接接到最后
                Merged[count]=ls[i];
                count++;
            }
            break;
        }
        if (j==end) {
            for (j=i; j<start+lenth; j++) {
                Merged[count]=ls[j];
                count++;
            }
            break;
        }
    }
}

void MergeSort(int ls[100], int n){//排序主函数
    int Merged[100],lenth=1,i,time=0;//创建两个列表，time用于交换两个列表
    while (lenth<n) {//当目前排序长度小于总长度的时候
        if (time%2==0) {
             for (i=0; i<n/lenth; i+=2) {//将列表进行分片
                 if ((i+2)*lenth<=n) {//假如长度不超，则按lenth长度分片
                     Merge(ls, Merged, lenth, i*lenth, (i+2)*lenth);
                 }
                 else{//否则保证不超过队尾
                     Merge(ls, Merged, lenth, i*lenth, n);
                 }
            }
            for (i=0; i<n; i++) {//输出排序后的结果
                printf("%d ",Merged[i]);
            }
            printf("\n");
        }
        else{//然后将两个列表交换，一个作为待排序，一个作为已排序，继续排序
            for (i=0; i<n/lenth; i+=2) {
                 if ((i+2)*lenth<=n) {
                     Merge(Merged, ls, lenth, i*lenth, (i+2)*lenth);
                 }
                 else{
                     Merge(Merged, ls, lenth, i*lenth, n);
                 }
            }
            for (i=0; i<n; i++) {
                printf("%d ",ls[i]);
            }
            printf("\n");
        }
        time++;//排序次数自加
        lenth*=2;//长度倍增
    }
}

int main() {
    int ls[100]={45,32,67,28,78,90,15,21,30,60,11},i,n=11;
    /*
    for (i=0; i<n; i++) {
        ls[i]=rand()%100;
    }
     */
    printf("Original List:\n");
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n\n");
    HeapSort(ls, n);
    //MergeSort(ls, n);
    printf("\nMerge Sorted List:\n");
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
    return 0;
}

