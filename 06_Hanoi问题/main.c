//
//  main.c
//  06_Hanoi问题
//
//  Created by 谢 on 2020/4/9.
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>

void hanoi(int,char,char,char);
void Move(int,char,char);

int main() {
    int n;
    scanf("%d",&n);
    hanoi(n,'X','Y','Z');//把x上的n个盘子经由y移动到z上
    return 0;
}

void hanoi(int n,char x,char y,char z){//n为需要移动的盘数
    if (n==1) {//x,y,z代表将x上的盘经由y移动到z
        Move(n,x,z);
    }
    else{
        hanoi(n-1, x, z, y);//首先将所有x上盘子经由z移动到y上
        Move(n,x,z);//将x上最底下的那个盘移动到z上
        hanoi(n-1, y, x, z);//在将y上的n-1个盘子经由x移动到z上
    }
}

void Move(int n,char a,char b){//移动函数，把第n号盘由a座移动到b座
    printf("Move No.%d:From %c to %c\n",n,a,b);
}
