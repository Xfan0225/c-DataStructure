//
//  main.c
//  10_谢尔排布
//
//  Created by 谢 on 2020/5/19.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void ShellSort(int ls[100],int n){
    int i,j,d=n,val,flag=1;
    while (d>1) {//内嵌冒泡排序
        d=d/2;
        for (i=0; i<d; i++) {//首先对折半的d进行遍历，方便后续进行移动
            while (flag==1) {
                flag=0;//先重置标志
                for (j=0; j<n/d-1; j++) {//然后对子序列做冒泡排序
                    if (ls[j*d+i]<ls[(j+1)*d+i]) {
                        flag=1;
                        val=ls[j*d+i];
                        ls[j*d+i]=ls[(j+1)*d+i];
                        ls[(j+1)*d+i]=val;
                    }
                }
            }
            flag=1;//重置标志
        }
    }
}

int main() {
    int i,ls[100],n=20;
    srand(5);
    for (i=0; i<n; i++) {
        ls[i]=rand()%100;
    }
    ShellSort(ls, n);
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
    return 0;
}
