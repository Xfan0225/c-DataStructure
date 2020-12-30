//
//  main.c
//  打印并置空线性表
//
//  Created by 谢 on 2020/3/9.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>

void printls(int*,int);
void nullls(int*);
void countls(int*,int,int);
void del(int,int,int*);
void insert(int,int*,int,int*,int);

int main() {
    int A[10]={1,2,3,5,5,5,7,8,9,10},B[5]={5,4,3,2,1};//用数组模拟线性表
    int n=10,m=5;//A表长为10,B表长为5
    
    /*作业2，输出并置空表
    printls(A, n);//先输出表
    nullls(&n);//将表置空
    printls(A, n);//再次输出置空后的表
     */
    
    /*作业3，统计表中特定元素出现的数目
    countls(A, n, 5);//统计表中数字5出现的次数
    countls(A, n, 0);//统计表中数字0出现的次数
     */
    
    //作业4，删除表中特定元素
    del(5, 10, A);//删除表中元素1
     //
    
    //insert(n, A, m, B, 5);
    return 0;
}

void printls(int *ls,int lenls){//输出线性表
    int i;
    if (lenls<=0) {//如果输入表长为0代表表已被置空
        printf("Error!List is NULL!\n");
    }
    else{
        for (i=0; i<lenls; i++) {
            printf("%d ",ls[i]);
        }
        printf("\n");
    }
}

void nullls(int* lenls){//置空表
    *lenls = 0;//将表长修改为0即为置空
}

void countls(int* ls,int lenls,int count){
    int i,ans=0;
    if (lenls<=0) {//如果输入表长为0代表表已被置空
        printf("Error!List is NULL!\n");
    }
    else{
        for (i=0; i<lenls; i++) {
            if (ls[i]==count) {
                ans++;
            }
        }
        printf("Number of %d is:%d\n",count,ans);
    }
}

void del(int num,int lenth,int* ls){//删除表中特定元素
    int i,j;
    for (i=0; i<lenth; i++) {
        if (ls[i]==num) {//找到删除元素时
            lenth--;//将表长-1
            for (j=i; j<lenth; j++) {//表从后一点开始整体向前挪动一位
                ls[j]=ls[j+1];
            }
            i--;
        }
    }
    printf("del %d ls:",num);
    for (i=0; i<lenth; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
}

void insert(int lenth,int* ls,int ins_lenth, int* ins_ls,int place){//插入线性表
    int i;
    for (i=lenth; i>=place; i--) {//从插入位置开始将表统一向后移插入表长度个单位
        ls[ins_lenth+i]=ls[i];
    }
    for (i=place; i<place+ins_lenth; i++) {//将插入表放入原表空缺部分
        ls[i]=ins_ls[i-place];
    }
    printf("Insert list:");
    for (i=0; i<lenth+ins_lenth; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
}
