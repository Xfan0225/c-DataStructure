//
//  main.c
//  附加题：骑士旅游
//
//  Created by 谢 on 2020/4/9.
//  Copyright © 2020 谢. All rights reserved.
//  本程序最多能跑到6*6，如果更高维数的话需要一定的搜索技巧

#include <stdio.h>
#include <stdlib.h>

int n,m,flagall=0,start_x,start_y;//储存旅行方法
int xmove[8]={1,1,-1,-1,2,2,-2,-2},ymove[8]={2,-2,2,-2,1,-1,1,-1};//马可以走的方向

void make(int,int,int,int map[][100]);
int* search(int,int,int map[][100]);

int main() {
    int i,j,map[100][100];
    scanf("%d%d",&m,&n);//存入棋盘行列
    scanf("%d%d",&start_x,&start_y);//存入初始点
    for (i=0; i<m; i++) {//初始化棋盘
        for (j=0; j<n; j++) {
            map[i][j]=-1;
        }
    }
    make(1,start_x-1,start_y-1,map);
    if (flagall==0) {
        printf("No Ans!\n");
    }
    return 0;
}

void make(int time,int x,int y,int map[][100]){
    int i,j,flag[8];//用递归的深度优先搜索方法解决
    if (time==n*m) {//假如遍历完成了64个，最后检查是否能回到原点
        for (i=0; i<8; i++) {
            if (x+xmove[i]==start_x-1&&y+ymove[i]==start_y-1) {
                printf("Find an answer!\n");//则输出地图
                map[x][y]=time;
                for (i=0; i<m; i++) {
                    for (j=0; j<n; j++) {
                        printf("%d ",map[i][j]);
                    }
                    printf("\n");
                }
                flagall=1;
                exit(0);//直接结束程序
            }
        }
    }
    map[x][y]=time;//否则为当前地图赋值
    for (i=0; i<8; i++) {
        flag[i]=0;
        if (x+xmove[i]>=0&&x+xmove[i]<m&&y+ymove[i]>=0&&y+ymove[i]<n) {//首先看是否越界
            if (map[x+xmove[i]][y+ymove[i]]<0) {//再看是否可行
                flag[i]=1;//可行则更改flag
            }
        }
    }
    for (i=0; i<8; i++) {
        if (*(flag+i)==1) {//然后对于所有可行点继续搜索
            make(time+1,x+xmove[i],y+ymove[i],map);
        }
    }
    map[x][y]=-1;//假如以上搜索失败，则说明该点不可行，还原到未经过的状态
}
