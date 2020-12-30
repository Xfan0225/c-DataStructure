//
//  main.c
//  附加题：八皇后
//
//  Created by 谢 on 2020/4/9.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>
int n,count=0;
void made(int,int*);

int main() {
    int i,ls[15];//用一个列表来储存,只按顺序输出每行棋的所在位置
    for (i=0; i<n; i++) {//首先将没有放置棋子的位置记为-1
        ls[i]=-1;
    }
    scanf("%d",&n);
    made(0, ls);//从0开始尝试
    printf("Amount of answer:%d\n",count);
    return 0;
}

void made(int depth,int* used){//depth代表遍历到第几行，used用来储存已经放置棋子的位置
    int i,j,flag=0,k;
    if (depth==n) {//假如遍历到最后一行并且可行，说明得到一组可行解，输出答案
        for (i=0; i<n; i++) {
            printf("%d ",used[i]);
        }
        printf("\n");
        count++;//并且计数器自加
    }
    else{//否则的话
        for (i=0; i<n; i++) {//用flag作为是否违反规则的标志,i为该行的第几个元素
            for (j=0; j<depth; j++) {//假如在上方存在棋子
                if (used[j]==i+1) {
                    flag=1;//肯定不是可行解
                }
            }
            if (flag==0) {//假如经历过上一轮考验，即上方不存在冲突
                for (k=i-depth; k<=i+depth; k++) {//则对对角线方向进行搜索
                    if (k<i&&k>=0) {//当k在0-i的阶段的时候,向左上搜索正对角线
                        if (used[depth-(i-k)]-1==k) {//假如在对角线上存在元素
                            flag=1;//则冲突
                        }
                    }
                    else if (k>i&&k<=n-1){//当k在i+1-n-1阶段的时候，向右上搜索反对角线
                        if (used[depth-(k-i)]-1==k) {//假如对角线上存在元素
                            flag=1;//则冲突
                        }
                    }
                }
            }
            if (flag==0) {//假如不冲突的话，则该不冲突的点可以落子
                used[depth]=i+1;//记录该点
                made(depth+1, used);//递归下一行可以落子的点
            }
            flag=0;//重置标志
        }
    }
}
