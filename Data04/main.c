//
//  main.c
//  Data04
//
//  Created by 谢 on 2020/4/4.
//在原序列中相对位置比它靠前的，也就是比它先入栈的，出栈顺序必须是逆序；
//在原序列中相对位置比它大的，也就是比它后入栈的，出栈顺序没有要求；
//以上两点可以间插进行。
//  Copyright © 2020 谢. All rights reserved.
//

#include <stdio.h>

void FindImpossibleRange(int,int*,int);
int* PushQueue(int*,int,int);
int* PopQueue(int*,int*,int);
int* PopStack(int*,int,int);
int* PushStack(int*,int,int);
void Trans(int);
void Func(int);

int main() {
    int stack[100],n,i,queue[100];
    int stack1[100],stack2[100],val;
    scanf("%d",&n);
    /*
    for (i=0; i<n; i++) {
        scanf("%d",&val);
        PushQueue(stack1, val,i);
    }*/
    for (i=0; i<n; i++) {
        scanf("%d",&stack[i]);
    }
    //PopQueue(stack1, stack2, n);
    FindImpossibleRange(n, stack, 1);
    //Trans(n);
    //Func(n);
    return 0;
}

void FindImpossibleRange(int n,int* stack,int start){
    int i,val=0;
    //排查规则如下：
    //对于出栈元素，在原序列中相对位置比它靠前的，也就是比它先入栈的，之后的顺序必须是逆序
    //在原序列中相对位置比它大的，也就是比它后入栈的，出栈顺序没有要求
    if (n-start<1) {//如果所有元素排查完，均符合顺序
        printf("Possible!\n");//则说明出栈顺序可行
        return;
    }
    else if (start<=n) {
        val=stack[start-1];
        for (i=start; i<n; i++) {
            if (stack[i]<val) {//用val储存比当前出栈元素最小
                val=stack[i];//用来判断是否逆序出栈
            }//假如比当前出栈值小的元素未逆序出栈
            if (stack[i]>val&&stack[i]<stack[start-1]) {
                printf("Impossible\n");
                return;
            }
        }//否则继续排查当前元素的前一个元素
        return FindImpossibleRange(n, stack, start+1);
    }
}

int* PushStack(int* stack,int num,int place){
    stack[place]=num;
    return stack;
}

int* PopStack(int* stack,int num,int place){
    printf("%d ",stack[place]);
    return stack;
}

int* PushQueue(int* stack1,int inp,int start){
    stack1[start]=inp;//入队函数与压栈相同，因为都是顺序进入
    return stack1;
}

int* PopQueue(int* stack1,int* stack2,int num){
    //出队方法：先把第一个栈的元素压入第二个栈进行换序，之后pop第二个栈的元素即可
    int i;//出队函数需要借助第二个栈
    for (i=0; i<num; i++) {//相当于把第一个栈的元素压入第二个栈
        stack2[i]=stack1[num-i-1];//这样队列的pop顺序就为正序了
    }
    for (i=num-1; i>=0; i--) {//想当于再把第二个栈的元素pop出来
        printf("%d ",stack2[i]);//就像直接pop队列中的元素
    }
    printf("\n");
    return stack2;
}

void Trans(int n){
    char stack[100];//用字符串模拟储存余数的栈
    int val,i=0;
    while (n>0) {
        val=n%16;
        switch (val) {//取余数，入栈
            case 0:stack[i]='0';break;
            case 1:stack[i]='1';break;
            case 2:stack[i]='2';break;
            case 3:stack[i]='3';break;
            case 4:stack[i]='4';break;
            case 5:stack[i]='5';break;
            case 6:stack[i]='6';break;
            case 7:stack[i]='7';break;
            case 8:stack[i]='8';break;
            case 9:stack[i]='9';break;
            case 10:stack[i]='A';break;
            case 11:stack[i]='B';break;
            case 12:stack[i]='C';break;
            case 13:stack[i]='D';break;
            case 14:stack[i]='E';break;
            case 15:stack[i]='F';break;
            default:break;
        }
        i++;
        n/=16;
    }
    printf("Ans:0X");
    for (n=i-1; n>=0; n--) {//逆序输出字符串，模拟出栈
        printf("%c",stack[n]);
    }
    printf("\n");
}

void Func(int n){
    int stack[100],i=0,ans=1;
    stack[i]=n;
    i++;
    while (n>0) {//将n//2的值压入栈
        stack[i]=n/2;
        i++;
        n/=2;
    }
    stack[i]=0;
    for (n=i; n>=0; n--) {//最后出栈相乘即可
        if (stack[n]==0) {
            ans=1;
        }
        else{
            ans*=stack[n];
        }
    }
    printf("Ans:%d\n",ans);
}
