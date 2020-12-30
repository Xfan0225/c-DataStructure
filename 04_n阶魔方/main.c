//
//  main.c
//  04_n阶魔方
//
//  Created by 谢 on 2020/4/9.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>

void createTube(int);
int main() {
    int n;
    scanf("%d",&n);
    createTube(n);
    return 0;
}

void createTube(int n){
    int ls[100][100],count=1,Next_x=0,Next_y=(n+1)/2-1,i,j,Now_x=0,Now_y=0;
    if (n%2==0) {//假如输入偶数则报错
        printf("InputError!\n");
        return;
    }
    for (i=0; i<n; i++) {//置零矩阵
        for (j=0; j<n; j++) {
            ls[i][j]=0;
        }
    }
    while (count<=n*n) {//用count来计数生成的次数
        ls[Next_x][Next_y]=count;//首先将上次循环生成的下一次的序号给当前位置的矩阵赋值
        count++;//计数器自加
        Now_x=Next_x;Now_y=Next_y;//储存当前的x，y坐标
        Next_x--;Next_y--;//先移动x，y坐标，然后再进行检查
        if (Next_x<0) {//假如顶部越界
            Next_x=n-1;//将顶部移到底部
        }
        if (Next_y<0) {//假如左侧越界
            Next_y=n-1;//将左侧移到右侧
        }
        if (ls[Next_x][Next_y]>0) {//假如下一个位置已被填充
            Next_x=Now_x+1;Next_y=Now_y;//填充当前位置下面的元素
        }
    }
    for (i=0; i<n; i++) {//循环输出魔方
        for (j=0; j<n; j++) {
            printf("%d\t",ls[i][j]);
        }
        printf("\n");
    }
}
