//
//  main.c
//  09_快速排序
//
//  Created by 谢 on 2020/5/19.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void QuickSort(int ls[100],int left,int right){
    int i,last,val;
    if (left<right) {//假如左边比右边小
        last=left;//将最后交换值设为最左，最后last所指即为该元素所在位置
        for (i=left+1; i<right; i++) {//从最后交换值的后一个开始遍历
            if (ls[i]<ls[left]) {//假如该值比最左元素要小
                last++;//将最后交换值点向后移动一个（多了一个小于最初交换值的元素），并且跟该最小元素进行互换
                val=ls[last];
                ls[last]=ls[i];
                ls[i]=val;
            }
        }
        val=ls[left];//最后将最左元素放到正确的位置
        ls[left]=ls[last];
        ls[last]=val;
        QuickSort(ls, left, last-1);//将正确位置的左右元素继续递归
        QuickSort(ls, last+1, right);
    }
}

int main() {
    int i,ls[100],n=20;
    srand(5);
    for (i=0; i<n; i++) {
        ls[i]=rand()%100;
    }
    QuickSort(ls, 0, n);
    for (i=0; i<n; i++) {
        printf("%d ",ls[i]);
    }
    printf("\n");
    return 0;
}
